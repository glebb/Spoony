#include "level3.h"

#include "ground.h"
#include "hole.h"

#include "movingtriangle.h"
#include "spoonysprite.h"
#include "globals.h"

Level3::Level3(QGraphicsScene *scene, SpoonyMessage *m, SoundHandler *sound, QTimer *timer, QObject *parent) :
    Level(scene, m, sound, timer, parent)
{
    _name = "JUMPING SPOONY";
}

void Level3::play()
{
    _scene->setBackgroundBrush(QPixmap(":/images/bg.png"));
    Ground *g = new Ground(0,HEIGHT-GRASS_HEIGHT,WIDTH, GRASS_HEIGHT, ":/images/grass.png");
    _scene->addItem(g);
    MovingTriangle *t = new MovingTriangle(_timer, WIDTH, HEIGHT-GRASS_HEIGHT, -3);
    _scene->addItem(t);
    MovingTriangle *t2 = new MovingTriangle(_timer, WIDTH + WIDTH / 3,HEIGHT-GRASS_HEIGHT, -3);
    _scene->addItem(t2);

    spoony->setPos(DEFAULT_START_POSITION);
    _scene->addItem(spoony);
    _scene->setFocusItem(spoony);
    spoony->setSelected(true);
    killers.append(t);
    killers.append(t2);

}
