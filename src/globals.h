#ifndef GLOBALS_H
#define GLOBALS_H

#include <QPointF>
#include <QString>
#include "spoonysprite.h"

//const static int WIDTH = 640;
//const static int HEIGHT = 360;
const static int WIDTH = 840;
const static int HEIGHT = 480;
const static int GRASS_HEIGHT = 100;
const static int DEFAULT_SPEED = 30;
const static int LIVES = 3;
const static QPointF DEFAULT_START_POSITION = QPointF(0,HEIGHT-GRASS_HEIGHT-SpoonySprite::spriteHeight);

#endif // GLOBALS_H
