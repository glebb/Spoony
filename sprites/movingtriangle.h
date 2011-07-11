#ifndef MOVINGTRIANGLE_H
#define MOVINGTRIANGLE_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPolygonF>

#include "basicsprite.h"


class QPainter;

class MovingTriangle : public BasicSprite
{
    Q_OBJECT
public:
    MovingTriangle(QTimer *timer, int _x, int _y, int _speed, QGraphicsItem * parent = 0);
    ~MovingTriangle();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/,QWidget */*widget*/);
    QRectF boundingRect() const;

    QPainterPath shape() const;

public slots:
    void move();


private:
    QTimer *timer;

    int _x;
    int _y;
    int _speed;
    int _size;
    QPolygonF _p;


};
#endif // MOVINGTRIANGLE_H
