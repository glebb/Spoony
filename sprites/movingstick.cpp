#include "movingstick.h"

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

#include "globals.h"


MovingStick::MovingStick(QTimer *timer, int x, int y, int width, int height, int speed, QGraphicsItem * parent)
    :BasicSprite(_x, _y, _width, _height, parent), timer(timer), _x(x), _y(y), _width(width), _height(height), _speed(speed)
{
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    start = WIDTH;
    end = 0;
}

MovingStick::~MovingStick()
{

}

void MovingStick::paint(QPainter* painter, const QStyleOptionGraphicsItem*/*option*/,QWidget*/*widget*/)
{
    painter->fillRect(boundingRect(), Qt::cyan);
//    painter->drawPath(shape());
}

QRectF MovingStick::boundingRect() const
{
    QRectF r(_x,_y, _width, _height);
    //r.adjust(40,100,80,300);
    return r;
}

QPainterPath MovingStick::shape() const
{
    QPainterPath path;
    QRectF r = boundingRect();
    r.adjust(0, -50, 0, 50);
    path.addRect(boundingRect());
    return path;
}

void MovingStick::move()
{
    setPos(pos().x() + _speed, pos().y());
    if (pos().x() < end)
        setPos(start, pos().y());
}

void MovingStick::setLimits(int start, int end)
{
    this->start = start;
    this->end = end;
}
