#include "testinputhandler.h"

#include "inputhandler.h"
#include "spoonysprite.h"
#include "movehandler.h"
#include "spoonymessaging.h"
#include "fakegraphics.h"

#include <QtTest/QtTest>

InputHandlerSpec::InputHandlerSpec()
{
}

void InputHandlerSpec::init()
{
    i = new InputHandler;
    m = new SpoonyMessage;
    spoony = new SpoonySprite(m, new FakeSoundHandler);

}

void InputHandlerSpec::cleanup()
{
    delete spoony;
    delete m;
    delete i;

}

void InputHandlerSpec::keyDownShouldMovePlayerLeftWithLeft()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(spoony, event);
    QVERIFY(spoony->move.goingLeft);
    delete event;
}

void InputHandlerSpec::keyDownShouldMovePlayer()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(spoony, event);
    QVERIFY(spoony->move.moving);
    delete event;
}

void InputHandlerSpec::keyDownShouldNotMovePlayerRightWithLeftKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(spoony, event);
    QVERIFY(!spoony->move.goingRight);
    delete event;
}

void InputHandlerSpec::keyDownShouldMovePlayerRightWithRightKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(spoony, event);
    QVERIFY(spoony->move.goingRight);
    delete event;
}

void InputHandlerSpec::keyDownShouldNorMovePlayerLeftWithRightKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(spoony, event);
    QVERIFY(!spoony->move.goingLeft);
    delete event;
}


void InputHandlerSpec::keyDownShouldMakePlayerJumpWithUpKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777235, 0, 0);
    i->keyDown(spoony, event);
    QVERIFY(spoony->move.jumping);
    delete event;
}

void InputHandlerSpec::keyUpShouldStopMovement()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(spoony, event);
    delete event;
    event = new QKeyEvent(QEvent::KeyRelease, 16777236, 0, 0);
    i->keyUp(spoony, event);
    QVERIFY(!spoony->move.moving);
    delete event;
}

void InputHandlerSpec::keyDownShouldHandleJumpAndMoveAtSameTime()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(spoony, event);
    delete event;
    QVERIFY(!spoony->move.jumping);

    event = new QKeyEvent(QEvent::KeyPress, 16777235, 0, 0);
    i->keyDown(spoony, event);
    QVERIFY(spoony->move.moving);
    QVERIFY(spoony->move.jumping);
    delete event;
}
