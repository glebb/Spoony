#ifndef LEVEL3_H
#define LEVEL3_H

#include "level.h"

class Level3 : public Level
{
    Q_OBJECT
public:
    Level3(QGraphicsScene *_scene, SnoopyMessaging *m, SoundHandler *sound, QTimer *_timer, QObject *parent = 0);

    void play();

signals:

public slots:

};
#endif // LEVEL3_H
