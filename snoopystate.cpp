#include "snoopystate.h"

SnoopyState::SnoopyState(SnoopySprite* snoopy)
    :QState(0),_snoopy(snoopy)
{
}

void SnoopyState::onEntry ( QEvent * /*event*/ )
{
    //connect tick signal from prince
    QObject::connect(_snoopy,SIGNAL(tick()),this,SLOT(nextFrame()));
}

void SnoopyState::onExit ( QEvent * /*event*/ )
{
    //disconnect tick signal from prince
    QObject::disconnect(_snoopy,SIGNAL(tick()),this,SLOT(nextFrame()));
}

void SnoopyState::nextFrame()
{
    //do nothing
}
