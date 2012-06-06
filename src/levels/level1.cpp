#include "level1.h"

#include <QGraphicsScene>
#include <QTimer>

#include "ground.h"
#include "hole.h"
#include "spoonysprite.h"
#include "globals.h"

Level1::Level1(QGraphicsScene *scene, SpoonyMessage *m, SoundHandler *sound, QTimer *timer,
               QObject *parent) : Level(scene, m, sound, timer, parent)
{
    _name = "LOOK OUT SPOONY";
}

Level1::~Level1()
{
}

void Level1::play()
{

    _scene->setBackgroundBrush(QPixmap(":/images/chengdu.png"));
    _g = new Ground(0,HEIGHT-GRASS_HEIGHT, WIDTH / 2, GRASS_HEIGHT, ":/images/grass.png");
    _scene->addItem(_g);

    _g2 = new Ground(WIDTH / 2 +120,HEIGHT-GRASS_HEIGHT,WIDTH-120, GRASS_HEIGHT, ":/images/grass.png");
    _scene->addItem(_g2);

    _hole = new Hole(WIDTH / 2, HEIGHT-GRASS_HEIGHT, 120, GRASS_HEIGHT);
    _scene->addItem(_hole);

    spoony->setPos(DEFAULT_START_POSITION);
    _scene->addItem(spoony);
    _scene->setFocusItem(spoony);
    spoony->setSelected(true);

    addKillObjects(_hole);
}
