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
    int _selectId; //被选棋子

    //QPoint _cleckId;

    Stone _s[12]; //定义12颗棋子

    /*极坐标转化成棋子的像素坐标*/
    QPoint polarCoordToXY(QPoint , double angle, double r);
    QPoint polarCoordToXY(QPoint , int id);

    /*将变换坐标还原成像素坐标*/
    QPoint transpCoordToXY(QPoint &);

    /*像素坐标转成棋子的极点坐标并判断是否有子*/
    bool getPolarCoord(QPoint, int &angle, int &r);

    /*绘制棋盘及棋子*/
    void paintEvent(QPaintEvent *);
    void drawStone(QPainter &, QPoint &, int id);

    /*基本走棋*/
    void mouseReleaseEvent(QMouseEvent *);

    /*获取点击位置的圈数*/
    int getLaps(int r);

};

#endif // BOARD_H
