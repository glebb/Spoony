#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"

class Level2 : public Level
{
    Q_OBJECT
public:
    Level2(QGraphicsScene *_scene, SnoopyMessage *m, SoundHandler *sound, QTimer *_timer, QObject *parent = 0);

    void play();

signals:

public slots:

};

#endif // LEVEL2_H
