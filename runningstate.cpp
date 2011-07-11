#include "runningstate.h"

#include <QDebug>

RunningState::RunningState(SnoopySprite* snoopy)
    :SnoopyState(snoopy)
{
    _counter = 0;
}

void RunningState::nextFrame()
{
    if (_counter == 0)
    {
        _snoopy->_y = 0;
        _snoopy->_x += 1;
        if (_snoopy->_x >= 4 )
            _snoopy->_x = 0;
    }
    _counter++;
    if (_counter == 3) _counter = 0;
}

void RunningState::onEntry ( QEvent * event )
{
    SnoopyState::onEntry(event);
//    _snoopy->_y = 0;
//    _snoopy->_x = 0;
}

void RunningState::onExit ( QEvent * event )
{
    SnoopyState::onExit(event);
//    _snoopy->_y = 0;
//    _snoopy->_x = 0;
}
