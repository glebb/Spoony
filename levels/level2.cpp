#include "level2.h"
#include "ground.h"
#include "hole.h"
#include "snoopysprite.h"
#include "globals.h"

Level2::Level2(QGraphicsScene *scene, SnoopyMessaging *m, SoundHandler *sound, QTimer *timer, QObject *parent) :
    Level(scene, m, sound, timer, parent)
{
    _name = "WAS THIS IN THE ORIGINAL?";
}

void Level2::play()
{
    _scene->setBackgroundBrush(QPixmap(":/images/kambodza.png"));
    Ground *g = new Ground(0,HEIGHT-GRASS_HEIGHT,WIDTH / 3, GRASS_HEIGHT, ":/images/ground.png");
    _scene->addItem(g);

    Hole *hole = new Hole(WIDTH / 3, HEIGHT-GRASS_HEIGHT, 120, GRASS_HEIGHT);
    _scene->addItem(hole);

    Ground *g2 = new Ground(WIDTH / 3+120,HEIGHT-GRASS_HEIGHT,80, GRASS_HEIGHT, ":/images/ground.png");
    _scene->addItem(g2);

    Hole *hole2 = new Hole(WIDTH / 3+120+80, HEIGHT-GRASS_HEIGHT, 120, GRASS_HEIGHT);
    _scene->addItem(hole2);

    Ground *g3 = new Ground(WIDTH / 3+120+80+120, HEIGHT-GRASS_HEIGHT,WIDTH-WIDTH / 3-120, GRASS_HEIGHT, ":/images/ground.png");
    _scene->addItem(g3);

    snoopy->setPos(DEFAULT_START_POSITION);
    _scene->addItem(snoopy);
    _scene->setFocusItem(snoopy);
    snoopy->setSelected(true);

    addKillObjects(hole);
    addKillObjects(hole2);

}
