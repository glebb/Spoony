#include "level4.h"

#include <QGraphicsScene>
#include <QTimer>

#include "ground.h"
#include "hole.h"
#include "snoopysprite.h"
#include "globals.h"
#include "movingstick.h"


Level4::Level4(QGraphicsScene *_scene, SnoopyMessage *m, SoundHandler *sound,
               QTimer *_timer, QObject *parent):
    Level(_scene, m, sound, _timer, parent)
{
    _name = "UNNAMED";
}

void Level4::play()
{
    _scene->setBackgroundBrush(QPixmap(":/images/chengdu.png"));


    Ground *g3 = new Ground(WIDTH / 3.5, HEIGHT-GRASS_HEIGHT +5, WIDTH - (WIDTH / 3.5 * 2), GRASS_HEIGHT - 5, ":/images/water.png");
    _scene->addItem(g3);
    g3->solid = false;

    MovingStick *s2 = new MovingStick(_timer, WIDTH - WIDTH / 3.5, HEIGHT-GRASS_HEIGHT, 160, 20, -2);
    s2->setLimits(0, -(WIDTH - (WIDTH / 3.5 * 2)) - 160 + 20);
    _scene->addItem(s2);
    s2->solid = true;

    MovingStick *s = new MovingStick(_timer, WIDTH - WIDTH / 3.5 + 280, HEIGHT-GRASS_HEIGHT, 160, 20, -2);
    s->setLimits(-280, -(WIDTH - (WIDTH / 3.5 * 2)) - 160 - 280 + 20);
    _scene->addItem(s);
    s->solid = true;



    Ground *g = new Ground(0,HEIGHT-GRASS_HEIGHT, WIDTH / 3.5, GRASS_HEIGHT, ":/images/grass.png");
    _scene->addItem(g);

    Ground *g2 = new Ground(WIDTH - WIDTH / 3.5, HEIGHT-GRASS_HEIGHT, WIDTH / 3.5, GRASS_HEIGHT, ":/images/grass.png");
    _scene->addItem(g2);

    BasicSprite *b = new BasicSprite(WIDTH / 3.5, HEIGHT-GRASS_HEIGHT - 20,
                                     20, GRASS_HEIGHT + 20);
    b->setColor(Qt::black);
    _scene->addItem(b);

    BasicSprite *b2 = new BasicSprite(WIDTH - WIDTH / 3.5, HEIGHT-GRASS_HEIGHT - 20,
                                     20, GRASS_HEIGHT + 20);
    b2->setColor(Qt::black);
    _scene->addItem(b2);


    snoopy->setPos(DEFAULT_START_POSITION);
    _scene->addItem(snoopy);
    _scene->setFocusItem(snoopy);
    snoopy->setSelected(true);

    addKillObjects(g3);
    addKillObjects(b);
    addKillObjects(b2);

}
