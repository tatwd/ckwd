#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);
    ~Board();

    int _R; //棋盘外圆半径
    int _r; //棋盘内圆半径

    int _angle;  //弧半角
    int _h;      //弧矩形半高
    int _w;      //弧矩形半宽

    virtual void paintEvent(QPaintEvent *);

    virtual void drawStone(QPainter& painter);

private:
    Ui::Board *ui;
};

#endif // BOARD_H
