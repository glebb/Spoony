#include "levelfactory.h"

#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "spoonymessaging.h"
#include "soundhandler.h"

#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

LevelFactory::LevelFactory()
{
}

Level* LevelFactory::create(int level_number, QGraphicsScene *main_scene,
                             SpoonyMessage *spoony_message, SoundHandler *sound_handler, QTimer *global_timer, QObject *parent)
{
    Level *level;
    switch (level_number)
    {
        case 1:
            level = new Level1(main_scene, spoony_message, sound_handler, global_timer, parent);
            break;
        case 2:
            level = new Level3(main_scene, spoony_message, sound_handler, global_timer, parent);
            break;
        case 3:
            level = new Level2(main_scene, spoony_message, sound_handler, global_timer, parent);
            break;
        case 4:
            level = new Level4(main_scene, spoony_message, sound_handler, global_timer, parent);
            break;
        default:
            level = new Level1(main_scene, spoony_message, sound_handler, global_timer, parent);
    }
    return level;

}
