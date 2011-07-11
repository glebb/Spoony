#include "fakegraphics.h"
#include <QGraphicsObject>
#include "soundhandler.h"

FakeGraphics::FakeGraphics(QGraphicsItem *parent) :
    BasicSprite(0, 0, 0, 0, parent)
{
}

FakeSoundHandler::FakeSoundHandler(QObject *parent) :
    SoundHandler(parent)
{

}
