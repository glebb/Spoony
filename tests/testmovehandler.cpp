#include "testmovehandler.h"

#include "snoopysprite.h"
#include "movehandler.h"
#include "snoopymessaging.h"
#include "globals.h"
#include "fakegraphics.h"
#include "soundhandler.h"

#include <QGraphicsScene>
#include <QtTest/QtTest>
#include <QRectF>


MoveHandlerSpec::MoveHandlerSpec()
{
}

void MoveHandlerSpec::init()
{
    messaging = new SnoopyMessage;
    snoopy = new SnoopySprite(messaging, new FakeSoundHandler);
    move_handler = new MoveHandler;
    move_handler->setSnoopy(snoopy);
}

void MoveHandlerSpec::cleanup()
{
    delete messaging;
    delete move_handler;
    delete snoopy;

}

void MoveHandlerSpec::moveSnoopyShouldEmitDieWhenDying()
{
    QSignalSpy stateSpy(move_handler, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move_handler->moveSnoopy();
    QCOMPARE(stateSpy.count(), 0);
    snoopy->dying = true;
    move_handler->moveSnoopy();
    QCOMPARE(stateSpy.count(), 1);
}

void MoveHandlerSpec::moveSnoopyShouldEmitJumpWhenJumping()
{
    QSignalSpy stateSpy(move_handler, SIGNAL(jump()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move_handler->moveSnoopy();
    QCOMPARE(stateSpy.count(), 0);
    move_handler->jumping = true;
    move_handler->moveSnoopy();
    QCOMPARE(stateSpy.count(), 1);
}

void MoveHandlerSpec::moveSnoopyShouldEmitCollideWhenColliding()
{
    QGraphicsScene *scene = new QGraphicsScene(0,0, 1000, 1000);
    scene->addItem(snoopy);
    snoopy->setPos(DEFAULT_START_POSITION);
    QSignalSpy stateSpy(move_handler, SIGNAL(collides()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move_handler->moveSnoopy();
    QCOMPARE(stateSpy.count(), 0);
    QRectF r(DEFAULT_START_POSITION.x(), DEFAULT_START_POSITION.y(), 300, 300); // Same location as Snoopy
    FakeGraphics *gfx2 = new FakeGraphics();
    gfx2->setBounds(r);
    scene->addItem(gfx2);
    move_handler->moveSnoopy();
    QCOMPARE(stateSpy.count(), 1);
    scene->removeItem(snoopy);
    delete scene;
}


void MoveHandlerSpec::moveSnoopyShouldMovePlayerLeftInXCoordinate()
{
    move_handler->moving = true;
    int originalLocation = snoopy->x();
    move_handler->goingLeft = true;
    move_handler->goingRight = false;
    move_handler->changeDir(snoopy);
    move_handler->moveSnoopy();
    QVERIFY(originalLocation > snoopy->x());
}

void MoveHandlerSpec::moveSnoopyShouldMovePlayerRightInXCoordinate()
{
    move_handler->moving = true;
    move_handler->goingLeft = false;
    move_handler->goingRight = true;
    move_handler->moveSnoopy();
    int originalLocation = snoopy->x();
    move_handler->moveSnoopy();
    QVERIFY(originalLocation < snoopy->x());
}

void MoveHandlerSpec::moveSnoopyShouldMovePlayerUpInYCoordinate()
{
    move_handler->jumping = true;
    int originalLocation = snoopy->y();
    move_handler->moveSnoopy();
    QVERIFY(originalLocation > snoopy->y());
}

void MoveHandlerSpec::deathShouldMakePlayerFallInYCoordinates()
{
    int originalLocation = snoopy->y();
    move_handler->death();
    QVERIFY(originalLocation < snoopy->y());

}

void MoveHandlerSpec::deathShouldEmitFinishedDying()
{
    QSignalSpy stateSpy(move_handler, SIGNAL(finishedDying()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    snoopy->dying = true;
    snoopy->setY(HEIGHT-1);
    while (snoopy->dying)
    {
        move_handler->death();
    }

    QCOMPARE(stateSpy.count(), 1);

}

void MoveHandlerSpec::changeDirShouldChangePlayerDirection()
{
    move_handler->goingRight = true;
    move_handler->changeDir(snoopy);
    QVERIFY(move_handler->goingLeft == true);
    QVERIFY(move_handler->goingRight == false);
    move_handler->changeDir(snoopy);
    QVERIFY(move_handler->goingLeft == false);
    QVERIFY(move_handler->goingRight == true);

}
