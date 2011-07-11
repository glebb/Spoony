#ifndef FAKEGRAPHICS_H
#define FAKEGRAPHICS_H

#include <QGraphicsObject>
#include <QObject>

#include "soundhandler.h"
#include "basicsprite.h"

class FakeGraphics : public BasicSprite
{
    Q_OBJECT
public:
    FakeGraphics(QGraphicsItem *parent = 0);
    QRectF bounds;
    void setBounds(QRectF b) { bounds = b; }
    QRectF boundingRect() const { return bounds; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        Q_UNUSED(painter); Q_UNUSED(option); Q_UNUSED(widget); }

signals:

public slots:

};

class FakeSoundHandler : public SoundHandler
{
    Q_OBJECT

public:
    FakeSoundHandler(QObject *parent = 0);
    void playSound(QString filename) { Q_UNUSED(filename); };
};



#endif // FAKEGRAPHICS_H
