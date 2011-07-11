#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"


class Ground;
class Hole;

class Level1 : public Level
{
    Q_OBJECT
public:
    Level1(QGraphicsScene *_scene, SnoopyMessaging *m, SoundHandler *sound, QTimer *_timer, QObject *parent = 0);
    ~Level1();

    void play();

private:
    Ground *_g;
    Ground *_g2;
    Hole *_hole;
};

#endif // LEVEL1_H
