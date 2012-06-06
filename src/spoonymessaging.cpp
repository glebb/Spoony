#include "spoonymessaging.h"

SpoonyMessage::SpoonyMessage(QObject *parent) :
    QObject(parent)
{
}

void SpoonyMessage::onDie()
{
    emit die();
}

void SpoonyMessage::onCollide()
{
    emit collides();
}

void SpoonyMessage::onFinish()
{
    emit finish();
}

void SpoonyMessage::onResetLevel()
{
    emit reset();
}
