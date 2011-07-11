#include "tst_testmovehandler.h"

#include "snoopysprite.h"
#include "movehandler.h"
#include "snoopymessaging.h"
#include "globals.h"
#include "fakegraphics.h"
#include "soundhandler.h"

#include <QGraphicsScene>
#include <QtTest/QtTest>
#include <QRectF>


TestMoveHandler::TestMoveHandler()
{
}

void TestMoveHandler::init()
{
    m = new SnoopyMessaging;
    snoopy = new SnoopySprite(m, new FakeSoundHandler);
    move = new MoveHandler;
    move->setSnoopy(snoopy);
}

void TestMoveHandler::cleanup()
{
    delete m;
    delete move;
    delete snoopy;

}

void TestMoveHandler::testEmitDieWhenDying()
{
    QSignalSpy stateSpy(move, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move->moveSnoopy();
    QCOMPARE(stateSpy.count(), 0);
    snoopy->dying = true;
    move->moveSnoopy();
    QCOMPARE(stateSpy.count(), 1);
}

void TestMoveHandler::testEmitJumpWhenJumping()
{
    QSignalSpy stateSpy(move, SIGNAL(jump()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move->moveSnoopy();
    QCOMPARE(stateSpy.count(), 0);
    move->jumping = true;
    move->moveSnoopy();
    QCOMPARE(stateSpy.count(), 1);
}

void TestMoveHandler::testEmitCollideWhenColliding()
{
    QGraphicsScene *scene = new QGraphicsScene(0,0, 1000, 1000);
    scene->addItem(snoopy);
    snoopy->setPos(DEFAULT_START_POSITION);
    QSignalSpy stateSpy(move, SIGNAL(collides()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move->moveSnoopy();
    QCOMPARE(stateSpy.count(), 0);
    QRectF r(DEFAULT_START_POSITION.x(), DEFAULT_START_POSITION.y(), 300, 300); // Same location as Snoopy
    FakeGraphics *gfx2 = new FakeGraphics();
    gfx2->setBounds(r);
    scene->addItem(gfx2);
    move->moveSnoopy();
    QCOMPARE(stateSpy.count(), 1);
    scene->removeItem(snoopy);
    delete scene;
}


void TestMoveHandler::testMovingLeftMovesSnoopyLeft()
{
    move->moving = true;
    int originalLocation = snoopy->x();
    move->goingLeft = true;
    move->goingRight = false;
    move->changeDir(snoopy);
    move->moveSnoopy();
    QVERIFY(originalLocation > snoopy->x());
}

void TestMoveHandler::testMovingRightMovesSnoopyRight()
{
    move->moving = true;
    move->goingLeft = false;
    move->goingRight = true;
    move->moveSnoopy();
    int originalLocation = snoopy->x();
    move->moveSnoopy();
    QVERIFY(originalLocation < snoopy->x());
}

void TestMoveHandler::testJumpingMakesSnoopyJump()
{
    move->jumping = true;
    int originalLocation = snoopy->y();
    move->moveSnoopy();
    QVERIFY(originalLocation > snoopy->y());
}

void TestMoveHandler::testSnoopyShouldFallOnDie()
{
    int originalLocation = snoopy->y();
    move->death();
    QVERIFY(originalLocation < snoopy->y());

}

void TestMoveHandler::testEmitFinishedDyingWhenFinishedDying()
{
    QSignalSpy stateSpy(move, SIGNAL(finishedDying()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    snoopy->dying = true;
    snoopy->setY(HEIGHT-1);
    while (snoopy->dying)
    {
        move->death();
    }

    QCOMPARE(stateSpy.count(), 1);

}

void TestMoveHandler::testChangeDirectionChangesDirection()
{
    move->goingRight = true;
    move->changeDir(snoopy);
    QVERIFY(move->goingLeft == true);
    QVERIFY(move->goingRight == false);
    move->changeDir(snoopy);
    QVERIFY(move->goingLeft == false);
    QVERIFY(move->goingRight == true);

}
