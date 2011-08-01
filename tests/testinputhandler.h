#ifndef TST_TESTINPUTHANDLER_H
#define TST_TESTINPUTHANDLER_H

#include <QtTest/QtTest>

class InputHandler;
class SnoopyMessaging;
class SnoopySprite;

class InputHandlerSpec : public QObject
{
    Q_OBJECT

public:
    InputHandlerSpec();

private Q_SLOTS:
    void init();
    void cleanup();
    void shouldMovePlayerLeft();
    void shouldMovePlayerRight();
    void shouldNotMovePlayerWithoutInput();
    void shouldMakePlayerJump();
    void shouldStopMovementOnKeyRelease();
    void shouldBePossibleJumpAndMoveAtSameTime();


private:
    InputHandler *i;
    SnoopyMessaging *m;
    SnoopySprite *snoopy;

};


#endif // TST_TESTINPUTHANDLER_H
