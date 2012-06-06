#include "runningstate.h"

#include <QDebug>

RunningState::RunningState(SpoonySprite* spoony)
    :SpoonyState(spoony)
{
    _counter = 0;
}

void RunningState::nextFrame()
{
    if (_counter == 0)
    {
        _spoony->_y = 0;
        _spoony->_x += 1;
        if (_spoony->_x >= 4 )
            _spoony->_x = 0;
    }
    _counter++;
    if (_counter == 3) _counter = 0;
}
