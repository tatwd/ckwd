#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

#include "Stone.h"

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();

    int _R;

    Stone _s[12]; //定义12颗棋子

    /*极坐标转化成棋子的像素坐标*/
    QPoint polarCoordToXY(QPoint &, double angle, double r);
    QPoint polarCoordToXY(QPoint &, int id);

    /*像素坐标转成棋子的极点坐标并判断是否有子*/
    bool getPolarCoord(QPoint, int &angle, int &r);

    void drawStone(QPainter &, QPoint &, int id); //棋子绘制

    void paintEvent(QPaintEvent *); //绘图
    //void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *); //点击释放

};

#endif // BOARD_H
