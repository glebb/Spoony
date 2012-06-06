#include "level.h"

#include <QDebug>

#include "spoonysprite.h"
#include "movehandler.h"
#include "soundhandler.h"
#include "globals.h"

Level::Level(QGraphicsScene *scene, SpoonyMessage *m, SoundHandler *sound,
             QTimer *timer, QObject *parent) :
    QObject(parent), _scene(scene), _timer(timer)
{
    spoony = new SpoonySprite(m, sound);
    connect(timer,SIGNAL(timeout()), spoony, SLOT(nextFrame()));
    connect(timer, SIGNAL(timeout()), &spoony->move, SLOT(moveSpoony()));
    connect(&spoony->move,SIGNAL(collides()), this, SLOT(onCollide()));
    connect(this,SIGNAL(die()), &spoony->move, SLOT(death()));
    connect(this,SIGNAL(die()), spoony, SLOT(playDeathSound()));
    spoony->setSelected(true);
    spoony->setFlags(spoony->flags() | QGraphicsItem::ItemIsFocusable);
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
    if (!spoony->dying && spoony->collidingItems().size() != 0)

    foreach(QGraphicsItem *i, killers)
    {
        if (spoony->collidesWithItem(i))
        {
            emit die();
        }
    }
}
