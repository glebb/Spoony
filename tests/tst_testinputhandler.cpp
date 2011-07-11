#include "tst_testinputhandler.h"

#include "inputhandler.h"
#include "snoopysprite.h"
#include "movehandler.h"
#include "snoopymessaging.h"
#include "fakegraphics.h"

#include <QtTest/QtTest>

TestInputHandler::TestInputHandler()
{
}

void TestInputHandler::init()
{
    i = new InputHandler;
    m = new SnoopyMessaging;
    snoopy = new SnoopySprite(m, new FakeSoundHandler);

}

void TestInputHandler::cleanup()
{
    delete snoopy;
    delete m;
    delete i;

}

void TestInputHandler::testLeftArrowDownMovesSnoopyLeft()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.moving);
    QVERIFY(snoopy->move.goingLeft);
    QVERIFY(!snoopy->move.goingRight);
    delete event;
}

void TestInputHandler::testRightArrowDownMovesSnoopyRight()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.moving);
    QVERIFY(snoopy->move.goingRight);
    QVERIFY(!snoopy->move.goingLeft);
    delete event;

}

void TestInputHandler::testNoMovementWithoutInput()
{
    QVERIFY(!snoopy->move.moving);
    QVERIFY(!snoopy->move.jumping);
}

void TestInputHandler::testUpArrowMakesSnoopyJump()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777235, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.jumping);
    delete event;
}

void TestInputHandler::testKeyReleaseStopsMoving()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777236, 0, 0);
    i->keyDown(snoopy, event);
    delete event;
    QVERIFY(snoopy->move.moving);
    event = new QKeyEvent(QEvent::KeyRelease, 16777236, 0, 0);
    i->keyUp(snoopy, event);
    QVERIFY(!snoopy->move.moving);
    delete event;
}

void TestInputHandler::testShouldBePossibleJumpAndMoveAtSameTime()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, 16777234, 0, 0);
    i->keyDown(snoopy, event);
    delete event;
    QVERIFY(snoopy->move.moving);
    QVERIFY(!snoopy->move.jumping);
    event = new QKeyEvent(QEvent::KeyPress, 16777235, 0, 0);
    i->keyDown(snoopy, event);
    QVERIFY(snoopy->move.moving);
    QVERIFY(snoopy->move.jumping);
    delete event;

}
