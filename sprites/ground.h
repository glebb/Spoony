#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QBrush>

#include "basicsprite.h"

class QPainter;


class Ground : public BasicSprite
{
    Q_OBJECT
public:
    Ground(int _x, int _y, int _width, int _height, QString texture, QGraphicsItem * parent = 0);
    ~Ground();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/,QWidget */*widget*/);
    QRectF boundingRect() const;
    QPainterPath shape() const;

private:
    QBrush _brush;

};

#endif // GROUND_H
