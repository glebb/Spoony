#include "testmovehandler.h"

#include "spoonysprite.h"
#include "movehandler.h"
#include "spoonymessaging.h"
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
    messaging = new SpoonyMessage;
    spoony = new SpoonySprite(messaging, new FakeSoundHandler);
    move_handler = new MoveHandler;
    move_handler->setSpoony(spoony);
}

void MoveHandlerSpec::cleanup()
{
    delete messaging;
    delete move_handler;
    delete spoony;

}

void MoveHandlerSpec::moveSpoonyShouldEmitDieWhenDying()
{
    QSignalSpy stateSpy(move_handler, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move_handler->moveSpoony();
    QCOMPARE(stateSpy.count(), 0);
    spoony->dying = true;
    move_handler->moveSpoony();
    QCOMPARE(stateSpy.count(), 1);
}

void MoveHandlerSpec::moveSpoonyShouldEmitJumpWhenJumping()
{
    QSignalSpy stateSpy(move_handler, SIGNAL(jump()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move_handler->moveSpoony();
    QCOMPARE(stateSpy.count(), 0);
    move_handler->jumping = true;
    move_handler->moveSpoony();
    QCOMPARE(stateSpy.count(), 1);
}

void MoveHandlerSpec::moveSpoonyShouldEmitCollideWhenColliding()
{
    QGraphicsScene *scene = new QGraphicsScene(0,0, 1000, 1000);
    scene->addItem(spoony);
    spoony->setPos(DEFAULT_START_POSITION);
    QSignalSpy stateSpy(move_handler, SIGNAL(collides()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    move_handler->moveSpoony();
    QCOMPARE(stateSpy.count(), 0);
    QRectF r(DEFAULT_START_POSITION.x(), DEFAULT_START_POSITION.y(), 300, 300); // Same location as Spoony
    FakeGraphics *gfx2 = new FakeGraphics();
    gfx2->setBounds(r);
    scene->addItem(gfx2);
    move_handler->moveSpoony();
    QCOMPARE(stateSpy.count(), 1);
    scene->removeItem(spoony);
    delete scene;
}


void MoveHandlerSpec::moveSpoonyShouldMovePlayerLeftInXCoordinate()
{
    move_handler->moving = true;
    int originalLocation = spoony->x();
    move_handler->goingLeft = true;
    move_handler->goingRight = false;
    move_handler->changeDir(spoony);
    move_handler->moveSpoony();
    QVERIFY(originalLocation > spoony->x());
}

void MoveHandlerSpec::moveSpoonyShouldMovePlayerRightInXCoordinate()
{
    move_handler->moving = true;
    move_handler->goingLeft = false;
    move_handler->goingRight = true;
    move_handler->moveSpoony();
    int originalLocation = spoony->x();
    move_handler->moveSpoony();
    QVERIFY(originalLocation < spoony->x());
}

void MoveHandlerSpec::moveSpoonyShouldMovePlayerUpInYCoordinate()
{
    move_handler->jumping = true;
    int originalLocation = spoony->y();
    move_handler->moveSpoony();
    QVERIFY(originalLocation > spoony->y());
}

void MoveHandlerSpec::deathShouldMakePlayerFallInYCoordinates()
{
    int originalLocation = spoony->y();
    move_handler->death();
    QVERIFY(originalLocation < spoony->y());

}

void MoveHandlerSpec::deathShouldEmitFinishedDying()
{
    QSignalSpy stateSpy(move_handler, SIGNAL(finishedDying()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    spoony->dying = true;
    spoony->setY(HEIGHT-1);
    while (spoony->dying)
    {
        move_handler->death();
    }

    QCOMPARE(stateSpy.count(), 1);

}

void MoveHandlerSpec::changeDirShouldChangePlayerDirection()
{
    move_handler->goingRight = true;
    move_handler->changeDir(spoony);
    QVERIFY(move_handler->goingLeft == true);
    QVERIFY(move_handler->goingRight == false);
    move_handler->changeDir(spoony);
    QVERIFY(move_handler->goingLeft == false);
    QVERIFY(move_handler->goingRight == true);

}
