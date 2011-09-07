#ifndef FAKELEVEL_H
#define FAKELEVEL_H

#include "level.h"

class SnoopyMessage;
class QTimer;
class QString;
class SoundHandler;

class FakeLevel : public Level
{
public:
    FakeLevel(QGraphicsScene *_scene, SnoopyMessage *m, SoundHandler *sound, QTimer *_timer, QObject *parent = 0);

    void play();
};

#endif // FAKELEVEL_H
