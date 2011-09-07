#include "level.h"

#include <QDebug>

#include "snoopysprite.h"
#include "movehandler.h"
#include "soundhandler.h"
#include "globals.h"

Level::Level(QGraphicsScene *scene, SnoopyMessage *m, SoundHandler *sound,
             QTimer *timer, QObject *parent) :
    QObject(parent), _scene(scene), _timer(timer)
{
    snoopy = new SnoopySprite(m, sound);
    connect(timer,SIGNAL(timeout()), snoopy, SLOT(nextFrame()));
    connect(timer, SIGNAL(timeout()), &snoopy->move, SLOT(moveSnoopy()));
    connect(&snoopy->move,SIGNAL(collides()), this, SLOT(onCollide()));
    connect(this,SIGNAL(die()), &snoopy->move, SLOT(death()));
    connect(this,SIGNAL(die()), snoopy, SLOT(playDeathSound()));
    snoopy->setSelected(true);
    snoopy->setFlags(snoopy->flags() | QGraphicsItem::ItemIsFocusable);
}

Level::~Level()
{
}

void Level::addKillObjects(QGraphicsObject *obj)
{
    killers.append(obj);
}

void Level::onCollide()
{
    if (!snoopy->dying && snoopy->collidingItems().size() != 0)

    foreach(QGraphicsItem *i, killers)
    {
        if (snoopy->collidesWithItem(i))
        {
            emit die();
        }
    }
}
