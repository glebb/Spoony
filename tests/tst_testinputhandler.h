#ifndef TST_TESTINPUTHANDLER_H
#define TST_TESTINPUTHANDLER_H

#include <QtTest/QtTest>

class InputHandler;
class SnoopyMessaging;
class SnoopySprite;

class TestInputHandler : public QObject
{
    Q_OBJECT

public:
    TestInputHandler();

private Q_SLOTS:
    void init();
    void cleanup();
    void testLeftArrowDownMovesSnoopyLeft();
    void testRightArrowDownMovesSnoopyRight();
    void testNoMovementWithoutInput();
    void testUpArrowMakesSnoopyJump();
    void testKeyReleaseStopsMoving();
    void testShouldBePossibleJumpAndMoveAtSameTime();


private:
    InputHandler *i;
    SnoopyMessaging *m;
    SnoopySprite *snoopy;

};


#endif // TST_TESTINPUTHANDLER_H
