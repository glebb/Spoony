#include "jumpingstate.h"


JumpingState::JumpingState(SnoopySprite* snoopy)
    :SnoopyState(snoopy)
{
    _counter = 0;
}
void JumpingState::onEntry ( QEvent * event )
{
    SnoopyState::onEntry(event);
//    _snoopy->_x = 1;
//    _snoopy->_y = 0;
//    _counter = 0;
}

void JumpingState::onExit ( QEvent * event )
{
    SnoopyState::onExit(event);
//    _snoopy->_x = 0;
//    _snoopy->_y = 0;
}

void JumpingState::nextFrame()
{
//    if (_counter < 15)
//    {
//        _snoopy->_y = 0;
//        _snoopy->_x += 0;
//    }
//    else
//    {
//        _snoopy->_x = 3;
//    }
//    _counter++;
//    if (_counter == 0)
//    {
//        _snoopy->_y = 0;
//        _snoopy->_x += 1;
//        if (_snoopy->_x >= 19 )
//            _snoopy->_x = 0;
//    }
//    _counter++;
//    if (_counter == 2) _counter = 0;


}
