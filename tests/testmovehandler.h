#ifndef TESTMOVEHANDLER_H
#define TESTMOVEHANDLER_H

#include <QtTest/QtTest>

#include "movehandler.h"

class SpoonyMessage;
class SpoonySprite;

class MoveHandlerSpec : public QObject
{
    Q_OBJECT

public:
    MoveHandlerSpec();

private Q_SLOTS:
    void init();
    void cleanup();

    void moveSpoonyShouldEmitDieWhenDying();
    void moveSpoonyShouldEmitJumpWhenJumping();
    void moveSpoonyShouldEmitCollideWhenColliding();
    void moveSpoonyShouldMovePlayerLeftInXCoordinate();
    void moveSpoonyShouldMovePlayerRightInXCoordinate();
    void moveSpoonyShouldMovePlayerUpInYCoordinate();
    void deathShouldMakePlayerFallInYCoordinates();
    void deathShouldEmitFinishedDying();
    void changeDirShouldChangePlayerDirection();

private:
    SpoonyMessage *messaging;
    SpoonySprite *spoony;
    MoveHandler *move_handler;

};



#endif // TESTMOVEHANDLER_H
