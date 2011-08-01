#ifndef TST_TESTMOVEHANDLER_H
#define TST_TESTMOVEHANDLER_H

#include <QtTest/QtTest>

#include "movehandler.h"

class SnoopyMessaging;
class SnoopySprite;

class MoveHandlerSpec : public QObject
{
    Q_OBJECT

public:
    MoveHandlerSpec();

private Q_SLOTS:
    void init();
    void cleanup();

    void shouldEmitDie();
    void shouldEmitJump();
    void shouldEmitCollide();
    void shouldMovePlayerLeft();
    void shouldMovePlayerRight();
    void shouldMakePlayerJump();
    void shouldMakePlayerDieOnFall();
    void shouldEmitFinishedDying();
    void shouldChangePlayerDirection();

private:
    SnoopyMessaging *m;
    SnoopySprite *snoopy;
    MoveHandler *move;

};



#endif // TST_TESTMOVEHANDLER_H
