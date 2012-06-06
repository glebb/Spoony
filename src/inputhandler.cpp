#include "inputhandler.h"
#include "spoonysprite.h"

InputHandler::InputHandler()
{
    _up = false;

    _leftPressed = false;
    _rightPressed = false;
}

InputHandler::~InputHandler()
{
}

bool InputHandler::keyDown(SpoonySprite *spoony, const QKeyEvent *event)
{
    bool ret = false;
    if (event->key() == 16777236)
    {
        ret = true;
        spoony->move.moving = true;
        _rightPressed = true;
        if (spoony->move.goingLeft)
        {
            spoony->move.changeDir(spoony);
        }
        spoony->move.goingRight = true;
        spoony->move.goingLeft = false;


    }

    if (event->key() == 16777234)
    {
        ret = true;
        spoony->move.moving = true;
        _leftPressed = true;
        if (spoony->move.goingRight)
        {
            spoony->move.changeDir(spoony);
        }
        spoony->move.goingLeft = true;
        spoony->move.goingRight = false;

    }

    if (event->key() == 16777235)
    {
        _up = true;
        if (!spoony->move.jumping)
            emit jump();
        spoony->move.jumping = true;
        ret = true;
    }

    return ret;
}

bool InputHandler::keyUp(SpoonySprite *spoony, const QKeyEvent *event)
{
    bool ret = false;
    if (event->key() == 16777234)
        _leftPressed = false;
    if (event->key() == 16777236)
        _rightPressed = false;

    if (!_leftPressed && !_rightPressed)
    {
        ret = true;
        spoony->move.moving = false;
    }

    if (!spoony->move.jumping && event->key() == 16777234) {
        ret = true;
        spoony->move.jumping = false;
    }
    return ret;

}
