#ifndef TST_TESTMOVEHANDLER_H
#define TST_TESTMOVEHANDLER_H

#include <QtTest/QtTest>

#include "movehandler.h"

class SnoopyMessaging;
class SnoopySprite;

class TestMoveHandler : public QObject
{
    Q_OBJECT

public:
    TestMoveHandler();

private Q_SLOTS:
    void init();
    void cleanup();

    void testEmitDieWhenDying();
    void testEmitJumpWhenJumping();
    void testEmitCollideWhenColliding();
    void testMovingLeftMovesSnoopyLeft();
    void testMovingRightMovesSnoopyRight();
    void testJumpingMakesSnoopyJump();
    void testSnoopyShouldFallOnDie();
    void testEmitFinishedDyingWhenFinishedDying();
    void testChangeDirectionChangesDirection();

private:
    SnoopyMessaging *m;
    SnoopySprite *snoopy;
    MoveHandler *move;

};



#endif // TST_TESTMOVEHANDLER_H
