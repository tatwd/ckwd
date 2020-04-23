#include "Board.h"

#include <QPainter>
#include <QMouseEvent>
#include <math.h>

Board::Board(QWidget *parent)
    : QWidget(parent)
{
    //_R = (height()/2)*18/25;

    for(int i = 0;i < 12;++i)
    {
        _s[i].init(i); //初始化棋子
    }
    _selectId = -1;
}

Board::~Board()
{

}
//-----------------------------------------棋盘及棋子的初始化---------------------------------------------------//
void Board::paintEvent(QPaintEvent *)
{
    //------------------------笔刷屏幕------------------------------//
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); //绘图抗锯齿

    //painter.setWindow(QRect(-350,250,700,500));

    painter.fillRect(rect(),Qt::white); //界面填充为白色

    double cx = width()/2;
    double cy = height()/2;

    painter.translate(cx,cy); //将屏幕中心设为(0,0)

    QPen pen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    //------------------------图片部分------------------------------//
    QImage img;
    img.load("../../Resources/img/bg1.jpg"); //加载背景图片
    painter.drawImage(QPoint(-cx, -cy), img);


    //------------------------画圆部分------------------------------//
    //_R = cy*18/25;
    _R = 180; //棋盘外圆半径
    QPoint ct(0,0); //圆心

    for(int i = 0;i < 2;++i)
    {
        int i_r = _R;
        if(i == 1)
            i_r = _R/3;
        painter.drawEllipse(ct,i_r,i_r); //画内外两圆
    }


    //------------------------画线部分------------------------------//
    for(int i = 0;i < 2;++i)
    {
        QPoint l_start(ct.x()+_R*i,ct.y()+_R*(i-1));
        QPoint l_end  (ct.x()-_R*i,ct.y()-_R*(i-1));

        painter.drawLine(l_start,l_end);
    }


    //------------------------画四条弧------------------------------//
    QPainterPath path;

    for(int i = 0;i < 4;++i)
    {
        int i_r = _R;
        QPoint startPoint = polarCoordToXY(ct, 30+90*i, i_r);     //当前点
        QPoint endPoint = polarCoordToXY(ct, -30+90*i, i_r);      //终止点
        QPoint ctrlPoint= polarCoordToXY(ct, 90*i, i_r*105/180);  //控制点

        path.moveTo(startPoint);           //移动到当前点
        path.quadTo(ctrlPoint,endPoint);   //设置二次贝塞尔曲线
        painter.drawPath(path);            //画二次贝塞尔曲线

    }


    //------------------------绘制棋子------------------------------//

    for(int i = 0;i < 12;++i)
    {
        drawStone(painter, ct, i);
    }

    //painter.setPen(Qt::red);
    //painter.drawEllipse(_cleckId, 5, 5);
}

/*极坐标转化成棋子的像素坐标*/
QPoint Board::polarCoordToXY(QPoint c, double angle, double r)
{
    QPoint pos;

    double _ang = angle*M_PI/180; //角度转弧度
    //double _ang = ang*16;

    pos.rx() = r*cos(_ang) + c.x();
    pos.ry() = c.y() - r*sin(_ang);

    return pos;
}
QPoint Board::polarCoordToXY(QPoint c, int id)
{
    return polarCoordToXY(c,_s[id]._polarAngle,_s[id]._polarDiameter);
}

/*画棋子模块，在paintEvent()中调用*/
void Board::drawStone(QPainter &painter, QPoint &c, int id)
{
    if(_s[id]._dead)
        return;

    int _r = 14; //棋子半径
    QPoint s_ct = polarCoordToXY(c, id); //获取棋子的像素坐标

    /*设置棋子颜色*/
    if(_s[id]._black)
    {
        painter.setPen(Qt::white);
        painter.setBrush(Qt::black);
    }
    else
    {
        painter.setPen(Qt::black);
        painter.setBrush(Qt::white);
    }

    painter.drawEllipse(s_ct,_r,_r);

    /*选中棋子效果*/
    if(id == _selectId)
    {
        painter.setPen(Qt::red);
        painter.drawEllipse(s_ct, _r/2, _r/2);
    }
}



//---------------------------------------------走棋---------------------------------------------------------//

/*将变换坐标还原成像素坐标*/
QPoint Board::transpCoordToXY(QPoint &pos)
{
    pos.rx() -= width()/2;
    pos.ry() -= height()/2;
    return pos;
}

void Board::mouseReleaseEvent(QMouseEvent *ev)
{
    //获取点击位置坐标
    QPoint pt = ev->pos();

    //将坐标还原成像素坐标
    pt = transpCoordToXY(pt);

    //将pt转化成棋子的极角、极径,然后判断此极点上是否有棋子

    int angle;
    int r;

    bool flag = getPolarCoord(pt, angle, r);

    if(flag == false)
        return ;


    int i;
    int clickId = -1;
    for(i = 0;i < 12;++i)
    {
        if(_s[i]._polarAngle == angle && _s[i]._polarDiameter == r && _s[i]._dead == false)
            break;
    }

    if(i < 12)
    {
        //_selectId = i;
        //update();
        clickId = i;
    }

    if(_selectId == -1)
    {
        if(clickId != -1)
        {
            _selectId = clickId;
            update();
        }
    }
    else
    {
        if(_selectId == clickId) //同颗棋子被点2次时
        {
            _selectId = -1;
            update();
        }
        else
        {
            if(clickId != -1) //点中棋子
            {
                //_s[clickId]._dead = true;
                clickId = -1;
                return;
            }

            /* 棋子移动时：
             * 极角变化为：0度 30度 90度
             * 极径变化为：0 _R/3 _R*7/18 _R*5/18
             * 共计12种组合
             */
//            int dAngle = abs(angle - _s[_selectId]._polarAngle);
//            int dR = abs(r - _s[_selectId]._polarDiameter);

//            struct {
//                int d_angle;
//                int d_r;
//            } d_pos[12] = {
//                {0,       0}, {30,       0}, {90,       0},
//                {0,    _R/3}, {30,    _R/3}, {90,    _R/3},
//                {0, _R*7/18}, {30, _R*7/18}, {90, _R*7/18},
//                {0, _R*5/18}, {30, _R*5/18}, {90, _R*5/18},
//            };
//            bool go = false;
//            for(int i = 0;i < 12;++i)
//            {
//                if(d_pos[i].d_angle == dAngle && d_pos[i].d_r == dR)
//                {
//                    go = true;
//                    break;
//                }
//            }
//            if(go == false)
//                return;

            //if(dAngle!=30 && dAngle!= 90 && dR!=_R/3 && dR!=_R*7/18 && dR!=_R*5/18)
            //    return;

            //将点中位置的极坐标赋给被选棋子
            _s[_selectId]._polarAngle = angle;
            _s[_selectId]._polarDiameter = r;

            _selectId = -1;

            update();
        }
    }

}

/*像素坐标转成棋子的极点坐标并判断是否有子*/
bool Board::getPolarCoord(QPoint pt, int &angle, int &r)
{
    int _r = 14;

    /*遍历最外层*/
    for(int i = 0;i < 12;++i)
    {
        angle = 30*i;
        r = _R;

        QPoint c = polarCoordToXY(QPoint(0, 0), angle, r);
        int dx = c.x() - pt.x();
        int dy = c.y() - pt.y();
        if((dx*dx + dy*dy) < _r*_r) return true;
    }

    /*遍历第2层,第3层及圆心*/
    for(int i = 0;i < 9;++i)
    {
        angle = 90*(i%4);
        r = _R*13/18;   //第2层

        if(i>3 && i<8)  //第3层
            r = _R/3;
        else if(i == 8) //圆心
            r = 0;

        QPoint c = polarCoordToXY(QPoint(0, 0), angle, r);
        int dx = c.x() - pt.x();
        int dy = c.y() - pt.y();
        if((dx*dx + dy*dy) < _r*_r) return true;
    }

    return false;
}










/*获取点击位置的圈数*/
int Board::getLaps(int r)
{
    const int R = 180; //记录棋盘半径
    int laps = 0;
    switch (r)
    {
    case R:
        break;
    case R*13/18:
        laps = 1;
        break;
    case R/3:
        laps = 2;
        break;
    case 0:
        laps = 3;
        break;
    }
    return laps;
}
