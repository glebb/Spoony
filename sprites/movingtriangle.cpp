#include "movingtriangle.h"

#include <QPainter>
#include <QRectF>
#include <QColor>
#include <QRgb>
#include <QPen>
#include <QRectF>
#include <QPolygonF>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

#include "basicsprite.h"

MovingTriangle::MovingTriangle(QTimer *timer, int x, int y, int speed, QGraphicsItem * parent)
    :BasicSprite(0,0,0,0,parent), timer(timer), _x(x), _y(y), _speed(speed)
{
    _size = 80;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    _p.append(QPointF(x, y));
    _p.append(QPointF(x + _size / 2, y-_size / 2));
    _p.append(QPointF(x + _size, y));
}

MovingTriangle::~MovingTriangle()
{

}

void MovingTriangle::paint(QPainter* painter, const QStyleOptionGraphicsItem*/*option*/,QWidget*/*widget*/)
{
    painter->setBrush(Qt::SolidPattern);
    painter->drawPolygon(_p);
//    painter->drawRect(boundingRect());
}

QRectF MovingTriangle::boundingRect() const
{
    QRectF r(_x,_y-_size/2,_size,_size/2);
    //r.adjust(40,100,80,300);
    return r;
}

QPainterPath MovingTriangle::shape() const
{
    QPainterPath path;
    path.addPolygon(_p);
    return path;
}

void MovingTriangle::move()
{
    setPos(pos().x() + _speed, pos().y());
    if (pos().x() < -_x - _size)
        setPos(scene()->width() - _x, pos().y());

}
