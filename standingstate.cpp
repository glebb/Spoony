#include "standingstate.h"
#include <QDebug>

StandingState::StandingState(SnoopySprite* snoopy)
    :SnoopyState(snoopy)
{
}
void StandingState::onEntry ( QEvent * event )
{
    SnoopyState::onEntry(event);
//    _snoopy->_x = 0;
//    _snoopy->_y = 0;
}

void StandingState::onExit ( QEvent * event )
{
    SnoopyState::onExit(event);
//    _snoopy->_x = 0;
//    _snoopy->_y = 0;
}
