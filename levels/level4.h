#ifndef LEVEL4_H
#define LEVEL4_H

#include "level.h"

class Level4 : public Level
{
public:
    Level4(QGraphicsScene *_scene, SnoopyMessaging *m,
            SoundHandler *sound, QTimer *_timer, QObject *parent = 0);
    void play();
};

#endif // LEVEL4_H
