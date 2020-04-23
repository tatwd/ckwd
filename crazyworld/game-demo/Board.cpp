#include "Board.h"
#include "ui_Board.h"

#include <QPainter>
//#include <math.h>

//#define PI 3.1415926

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); //绘图抗锯齿


    //画笔风格
    QPen pen(Qt::black,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(pen);
    //painter.setPen();

    _R = 200;
    _r = 70;

//    int  bx = QSize.;
//    int  by = QSize::wd;
    //画外圆
    painter.drawEllipse(QPoint(350,250),_R,_R);
    //画内圆
    painter.drawEllipse(QPoint(350,250),_r,_r);


    //画4个弧线
    _angle = 70;
    _h = 80;  //以左弧为参考
    _w = 50;

    //上弧
    int stAngle1 = -(90-_angle)*16;
    int spAngle1 = -2*_angle*16;
    QRect rect1((350-_h),(250-_R-_w),2*_h,2*_w);
    painter.drawArc(rect1,stAngle1,spAngle1);

    //左弧
    int stAngle2 = _angle*16;
    int spAngle2 = -2*_angle*16;
    QRect rect2((350-_R -_w),(250 - _h),2*_w,2*_h);
    painter.drawArc(rect2,stAngle2,spAngle2);

    //下弧
    int stAngle3 = (90-_angle)*16;
    int spAngle3 = 2*_angle*16;
    QRect rect3((350-_h),(250+_R-_w),2*_h,2*_w);
    painter.drawArc(rect3,stAngle3,spAngle3);

    //右弧
    int stAngle4 = (180-_angle)*16;
    int spAngle4 = 2*_angle*16;
    QRect rect4((350+_R-_w),(250-_h),2*_w,2*_h);
    painter.drawArc(rect4,stAngle4,spAngle4);


    //画横线
    painter.drawLine(QPoint(150,250),QPoint(550,250));
    //画纵线
    painter.drawLine(QPoint(350,50),QPoint(350,450));


    //画12颗棋子
    drawStone(painter);


}

void Board::drawStone(QPainter &painter)
{
//    painter.setPen(Qt::white);
//    QRadialGradient rg(QPointF(350,50),50,QPointF(350,55));
//    rg.setColorAt(0,Qt::black);
//    rg.setColorAt(2,Qt::white);
//  待改进
    int r = 14;

    painter.setPen(Qt::white);
    painter.setBrush(QColor(0,0,0));

    painter.drawEllipse(QPoint(350,50),r,r);
    painter.drawEllipse(QPoint(274,66),r,r);
    painter.drawEllipse(QPoint(425,66),r,r);
    painter.drawEllipse(QPoint(350,100),r,r);
    painter.drawEllipse(QPoint(166,174),r,r);
    painter.drawEllipse(QPoint(534,174),r,r);

    painter.setPen(Qt::black);
    painter.setBrush(QColor(225,225,225));

    painter.drawEllipse(QPoint(350,450),r,r);
    painter.drawEllipse(QPoint(350,400),r,r);
    painter.drawEllipse(QPoint(274,434),r,r);
    painter.drawEllipse(QPoint(425,434),r,r);
    painter.drawEllipse(QPoint(166,326),r,r);
    painter.drawEllipse(QPoint(534,326),r,r);
}
