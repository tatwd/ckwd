#include "Board.h"

#include <QPainter>
#include <QMouseEvent>
#include <math.h>

Board::Board(QWidget *parent)
    : QWidget(parent)
{
    for(int i = 0;i < 12;++i)
    {
        _s[i].init(i); //初始化棋子
    }
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


    //------------------------画圆部分------------------------------//
    _R = 180;
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
        QPoint startPoint = this->polarCoordToXY(ct,30+90*i,i_r);     //当前点
        QPoint endPoint = this->polarCoordToXY(ct,-30+90*i,i_r);      //终止点
        QPoint ctrlPoint= this->polarCoordToXY(ct,90*i,i_r*105/180);  //控制点

        path.moveTo(startPoint);           //移动到当前点
        path.quadTo(ctrlPoint,endPoint);   //设置二次贝塞尔曲线
        painter.drawPath(path);            //画二次贝塞尔曲线

    }


    //------------------------绘制棋子------------------------------//
    /*
    int _r = 12; //棋子半径

    int i_ang = 0;
    int _ang = 0; //半弧大小
    int i_r = 0;

    for(int i = 0;i < 11;++i)
    {
        if(i <= 5){
            _ang = 30;
            i_r = _R;
            if(i%3 == 2)
                i_ang += 90-3*_ang;
        }
        else if (i == 6) {
            i_r = 13*_R/18;
            _ang = 90;
            i_ang = 0;
        }
        else if (i == 8) {
            i_r = _R/3;
            _ang = 90;
            i_ang = 0;
        }
        else if(i == 10){
            i_r = 0;
            i_ang = 0;
            _ang = 0;
        }

        //对称画
        for(int j = 0;j < 2;++j)
        {
            QPoint s_ct = this->polarCoordToXY(ct,i_ang+180*j,i_r);
            painter.drawEllipse(s_ct,_r,_r);

            if(i_r == 0)
                break;
        }

        i_ang += _ang;
    }
    */

    for(int i = 0;i < 12;++i)
    {
        drawStone(painter, ct, i);
    }


}
QPoint Board::polarCoordToXY(QPoint &c, double angle, double r)
{
    QPoint pos;

    double _ang = angle*M_PI/180; //角度转弧度
    //double _ang = ang*16;

    pos.rx() = r*cos(_ang) + c.x();
    pos.ry() = c.y() - r*sin(_ang);

    return pos;
}

QPoint Board::polarCoordToXY(QPoint &c, int id)
{
    return polarCoordToXY(c,_s[id]._polarAngle,_s[id]._polarDiameter);
}

void Board::drawStone(QPainter &painter, QPoint &c, int id)
{
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
}



//---------------------------------------------走棋---------------------------------------------------------//
void Board::mouseReleaseEvent(QMouseEvent *ev)
{
    QPoint pt = ev->pos();

    //将pt转化成棋子的极角、极径
    //然后判断此极点上是否有棋子.


}

void Board::getPolarCoord(QPoint pt, int &angle, int &r)
{
    //遍历所有点
}










