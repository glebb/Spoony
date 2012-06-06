#include "spoonystate.h"

SpoonyState::SpoonyState(SpoonySprite* spoony)
    :QState(0),_spoony(spoony)
{
}

void SpoonyState::onEntry ( QEvent * /*event*/ )
{
    //connect tick signal from prince
    QObject::connect(_spoony,SIGNAL(tick()),this,SLOT(nextFrame()));
}

void SpoonyState::onExit ( QEvent * /*event*/ )
{
    //disconnect tick signal from prince
    QObject::disconnect(_spoony,SIGNAL(tick()),this,SLOT(nextFrame()));
}

void SpoonyState::nextFrame()
{
    //do nothing
}
