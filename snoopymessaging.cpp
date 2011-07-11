#include "snoopymessaging.h"

SnoopyMessaging::SnoopyMessaging(QObject *parent) :
    QObject(parent)
{
}

void SnoopyMessaging::onDie()
{
    emit die();
}

void SnoopyMessaging::onCollide()
{
    emit collides();
}

void SnoopyMessaging::onFinish()
{
    emit finish();
}

void SnoopyMessaging::onResetLevel()
{
    emit reset();
}
