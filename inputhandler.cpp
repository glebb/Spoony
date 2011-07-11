#include "inputhandler.h"
#include "snoopysprite.h"

InputHandler::InputHandler()
{
    _up = false;

    _leftPressed = false;
    _rightPressed = false;
}

InputHandler::~InputHandler()
{
}

bool InputHandler::keyDown(SnoopySprite *snoopy, const QKeyEvent *event)
{
    bool ret = false;
    if (event->key() == 16777236)
    {
        ret = true;
        snoopy->move.moving = true;
        _rightPressed = true;
        if (snoopy->move.goingLeft)
        {
            snoopy->move.changeDir(snoopy);
        }
        snoopy->move.goingRight = true;
        snoopy->move.goingLeft = false;


    }

    if (event->key() == 16777234)
    {
        ret = true;
        snoopy->move.moving = true;
        _leftPressed = true;
        if (snoopy->move.goingRight)
        {
            snoopy->move.changeDir(snoopy);
        }
        snoopy->move.goingLeft = true;
        snoopy->move.goingRight = false;

    }

    if (event->key() == 16777235)
    {
        _up = true;
        if (!snoopy->move.jumping)
            emit jump();
        snoopy->move.jumping = true;
        ret = true;
    }

    return ret;
}

bool InputHandler::keyUp(SnoopySprite *snoopy, const QKeyEvent *event)
{
    bool ret = false;
    if (event->key() == 16777234)
        _leftPressed = false;
    if (event->key() == 16777236)
        _rightPressed = false;

    if (!_leftPressed && !_rightPressed)
    {
        ret = true;
        snoopy->move.moving = false;
    }

    if (!snoopy->move.jumping && event->key() == 16777234) {
        ret = true;
        snoopy->move.jumping = false;
    }
    return ret;

}
