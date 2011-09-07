#include "snoopymessaging.h"

SnoopyMessage::SnoopyMessage(QObject *parent) :
    QObject(parent)
{
}

void SnoopyMessage::onDie()
{
    emit die();
}

void SnoopyMessage::onCollide()
{
    emit collides();
}

void SnoopyMessage::onFinish()
{
    emit finish();
}

void SnoopyMessage::onResetLevel()
{
    emit reset();
}
