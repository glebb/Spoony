#include "ground.h"
#include <QPainter>
#include <QRectF>
#include <QColor>
#include <QRgb>
#include <QPen>
#include <QRectF>
#include <QDebug>

Ground::Ground(int x, int y, int width, int height, QString texture, QGraphicsItem * parent)
    :BasicSprite(x, y, width, height, parent)
{
    _brush = QBrush(Qt::green, QPixmap(texture));
    solid = true;
}

Ground::~Ground()
{

}

void Ground::paint(QPainter* painter, const QStyleOptionGraphicsItem*/*option*/,QWidget*/*widget*/)
{
    painter->fillRect(_x,_y,_width,_height, _brush);
//    painter->drawPath(shape());

}

QRectF Ground::boundingRect() const
{
    QRectF r(_x,_y,_width, _height);
    //r.adjust(0,0,0,0);
    return r;

}

QPainterPath Ground::shape() const
{
    QRectF r = boundingRect();
    r.adjust(0,1,0,-1);
    QPainterPath path;
    path.addRect(r);
    return path;
}

