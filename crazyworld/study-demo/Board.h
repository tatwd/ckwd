#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    ~Board();

    int _R; //外圆半径

    QPoint getPos(QPoint &,int ang,int r); //极坐标转化
    void paintEvent(QPaintEvent *); //画图

signals:

public slots:
};

#endif // BOARD_H
