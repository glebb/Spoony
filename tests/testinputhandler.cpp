#include "testinputhandler.h"

#include "inputhandler.h"
#include "snoopysprite.h"
#include "movehandler.h"
#include "snoopymessaging.h"
#include "fakegraphics.h"

#include <QtTest/QtTest>

InputHandlerSpec::InputHandlerSpec()
{
}

void InputHandlerSpec::init()
{
    i = new InputHandler;
    m = new SnoopyMessaging;
    snoopy = new SnoopySprite(m, new FakeSoundHandler);

}

void InputHandlerSpec::cleanup()
{
    delete snoopy;
    delete m;
    delete i;

}

void InputHandlerSpec::keyDownShouldMovePlayerLeftWithLeft()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.goingLeft);
    delete event;
}

void InputHandlerSpec::keyDownShouldMovePlayer()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.moving);
    delete event;
}

void InputHandlerSpec::keyDownShouldNotMovePlayerRightWithLeftKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(!snoopy->move.goingRight);
    delete event;
}

void InputHandlerSpec::keyDownShouldMovePlayerRightWithRightKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.goingRight);
    delete event;
}

void InputHandlerSpec::keyDownShouldNorMovePlayerLeftWithRightKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(!snoopy->move.goingLeft);
    delete event;
}


void InputHandlerSpec::keyDownShouldMakePlayerJumpWithUpKey()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777235, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.jumping);
    delete event;
}

void InputHandlerSpec::keyUpShouldStopMovement()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(snoopy, event);
    delete event;
    event = new QKeyEvent(QEvent::KeyRelease, 16777236, 0, 0);
    i->keyUp(snoopy, event);
    QVERIFY(!snoopy->move.moving);
    delete event;
}

void InputHandlerSpec::keyDownShouldHandleJumpAndMoveAtSameTime()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(snoopy, event);
    delete event;
    QVERIFY(!snoopy->move.jumping);

    event = new QKeyEvent(QEvent::KeyPress, 16777235, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.moving);
    QVERIFY(snoopy->move.jumping);
    delete event;
}
