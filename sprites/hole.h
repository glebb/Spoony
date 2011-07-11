#ifndef HOLE_H
#define HOLE_H

#include <QGraphicsItem>
#include <QGraphicsObject>

#include "basicsprite.h"

class QPainter;

class Hole : public BasicSprite
{
    Q_OBJECT
public:
    Hole(int _x, int _y, int _width, int _height, QGraphicsItem * parent = 0);
    ~Hole();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/,QWidget */*widget*/);
    QRectF boundingRect() const;

private:

};
#endif // HOLE_H
