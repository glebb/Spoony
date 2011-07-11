#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include <QGraphicsObject>
#include <QRectF>

class BasicSprite : public QGraphicsObject
{
    Q_OBJECT

public:

    BasicSprite(int _x, int _y, int _width, int _height, QGraphicsItem * parent = 0);
//    ~BasicSprite();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/,QWidget */*widget*/);
    virtual QRectF boundingRect() const;
    virtual void setColor(Qt::GlobalColor c);

    virtual bool isSolidPlane();
    bool solid;

protected:
    int _x;
    int _y;
    int _width;
    int _height;
    Qt::GlobalColor c;

};

#endif // BASICSPRITE_H
