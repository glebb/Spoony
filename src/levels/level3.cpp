#include "level3.h"

#include "ground.h"
#include "hole.h"

#include "movingtriangle.h"
#include "snoopysprite.h"
#include "globals.h"

Level3::Level3(QGraphicsScene *scene, SnoopyMessage *m, SoundHandler *sound, QTimer *timer, QObject *parent) :
    Level(scene, m, sound, timer, parent)
{
    _name = "JUMPING SNOOPY";
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

    snoopy->setPos(DEFAULT_START_POSITION);
    _scene->addItem(snoopy);
    _scene->setFocusItem(snoopy);
    snoopy->setSelected(true);
    killers.append(t);
    killers.append(t2);

}
