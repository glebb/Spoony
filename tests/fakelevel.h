#ifndef FAKELEVEL_H
#define FAKELEVEL_H

#include "level.h"

class SnoopyMessaging;
class QTimer;
class QString;
class SoundHandler;

class FakeLevel : public Level
{
public:
    FakeLevel(QGraphicsScene *_scene, SnoopyMessaging *m, SoundHandler *sound, QTimer *_timer, QObject *parent = 0);

    void play();
};

#endif // FAKELEVEL_H
