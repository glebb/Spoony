#ifndef MOVINGSTICK_H
#define MOVINGSTICK_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPolygonF>

#include "basicsprite.h"



class QPainter;

class MovingStick : public BasicSprite
{
    Q_OBJECT
public:
    MovingStick(QTimer *timer, int _x, int _y, int width, int height, int _speed, QGraphicsItem * parent = 0);
    ~MovingStick();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/,QWidget */*widget*/);
    QRectF boundingRect() const;

    QPainterPath shape() const;

    void setLimits(int start, int end);

public slots:
    void move();


private:
    QTimer *timer;

    int _x;
    int _y;
    int _width;
    int _height;
    int _speed;

    int start;
    int end;


};

#endif // MOVINGSTICK_H
