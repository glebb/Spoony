#ifndef FAKELEVEL_H
#define FAKELEVEL_H

#include "level.h"

class SpoonyMessage;
class QTimer;
class QString;
class SoundHandler;

class FakeLevel : public Level
{
public:
    FakeLevel(QGraphicsScene *_scene, SpoonyMessage *m, SoundHandler *sound, QTimer *_timer, QObject *parent = 0);

    void play();
};

#endif // FAKELEVEL_H
