#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

class QGraphicsScene;
class SpoonyMessage;
class SoundHandler;
class QTimer;
class QObject;

#include "level.h"

class LevelFactory
{
public:
    LevelFactory();

    static Level* create(int level_number, QGraphicsScene *main_scene, SpoonyMessage *spoony_message, SoundHandler *sound_handler, QTimer *global_timer, QObject *parent);

private:
};

#endif // LEVELFACTORY_H
