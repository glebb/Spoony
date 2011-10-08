#include "hole.h"
#include <QPainter>
#include <QRectF>
#include <QColor>
#include <QRgb>
#include <QPen>
#include <QRectF>

Hole::Hole(int x, int y, int width, int height, QGraphicsItem * parent)
    :BasicSprite(x, y, width, height, parent)
{
}

Hole::~Hole()
{

}

void Hole::paint(QPainter* painter, const QStyleOptionGraphicsItem*/*option*/,QWidget*/*widget*/)
{
//    painter->drawPath(shape());
    painter->setOpacity(0);
    painter->fillRect(_x,_y,_width,_height, Qt::black);
}

QRectF Hole::boundingRect() const
{
    QRectF r(_x,_y,_width, _height);
    r.adjust(6,-1,-6,1);
    return r;
}
