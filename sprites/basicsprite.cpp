#include "basicsprite.h"
#include <QGraphicsObject>
#include <QPainter>

BasicSprite::BasicSprite(int x, int y, int width, int height, QGraphicsItem * parent):
    QGraphicsObject(parent), _x(x), _y(y), _width(width), _height(height)
{
    solid = false;
}

//BasicSprite::~BasicSprite()
//{

//}


QRectF BasicSprite::boundingRect() const
{
    return QRectF(_x, _y, _width, _height);
}

void BasicSprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->fillRect(boundingRect(), c);
}

void BasicSprite::setColor(Qt::GlobalColor c)
{
    this->c = c;
}

bool BasicSprite::isSolidPlane()
{
    return solid;
}
