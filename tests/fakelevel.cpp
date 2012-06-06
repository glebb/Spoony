#include "fakelevel.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QString>


FakeLevel::FakeLevel(QGraphicsScene *scene,  SpoonyMessage *m, SoundHandler *sound, QTimer *timer,
               QObject *parent) : Level(scene, m, sound, timer, parent)
{
    _name = "FAKE LEVEL";
}

void FakeLevel::play()
{

}
