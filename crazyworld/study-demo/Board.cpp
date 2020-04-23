#include "Board.h"

#include <QPainter>
#include <math.h>

Board::Board(QWidget *parent) : QWidget(parent)
{

}

Board::~Board()
{

}

QPoint Board::getPos(QPoint &c,int ang, int r)
{
    double _ang = ang*M_PI/180; //角度转弧度
    double s_x = r*cos(_ang)+c.x();
    double s_y = c.y()-r*sin(_ang);
    QPoint pos(s_x,s_y);
    return pos;
}

void Board::paintEvent(QPaintEvent *)
{
//------------------------画笔属性------------------------------//
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); //绘图抗锯齿

    //QPen pen(Qt::black,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    //painter.setPen(pen);


//------------------------画圆部分------------------------------//
    _R = 180;
    QPoint ct(300,250); //圆心

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
    /*TODO*/


//------------------------遍历测试------------------------------//
    int _r = 10; //棋子半径

    int i_ang = 0;
    int _ang = 0; //半弧大小
    int i_r = 0;

    for(int i = 0;i < 11;++i)
    {
        if(i <= 5){
            _ang = 25;
            i_r = _R;
            if(i%3 == 2)
                i_ang += 90-3*_ang;
        }
        else if (i == 6) {
            i_r = 2*_R/3;
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
            if(i<6 || i>7){ //暂时不画中间四个点
                QPoint s_ct = this->getPos(ct,i_ang+180*j,i_r);
                painter.drawEllipse(s_ct,_r,_r);
            }

            if(i_r == 0)
                break;
        }

        i_ang += _ang;
    }

}
