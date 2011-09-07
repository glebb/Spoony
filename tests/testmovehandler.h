#ifndef TESTMOVEHANDLER_H
#define TESTMOVEHANDLER_H

#include <QtTest/QtTest>

#include "movehandler.h"

class SnoopyMessage;
class SnoopySprite;

class MoveHandlerSpec : public QObject
{
    Q_OBJECT

public:
    MoveHandlerSpec();

private Q_SLOTS:
    void init();
    void cleanup();

    void moveSnoopyShouldEmitDieWhenDying();
    void moveSnoopyShouldEmitJumpWhenJumping();
    void moveSnoopyShouldEmitCollideWhenColliding();
    void moveSnoopyShouldMovePlayerLeftInXCoordinate();
    void moveSnoopyShouldMovePlayerRightInXCoordinate();
    void moveSnoopyShouldMovePlayerUpInYCoordinate();
    void deathShouldMakePlayerFallInYCoordinates();
    void deathShouldEmitFinishedDying();
    void changeDirShouldChangePlayerDirection();

private:
    SnoopyMessage *messaging;
    SnoopySprite *snoopy;
    MoveHandler *move_handler;

};



#endif // TESTMOVEHANDLER_H
