#ifndef TESTINPUTHANDLER_H
#define TESTINPUTHANDLER_H

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
    void keyDownShouldMovePlayer();
    void keyDownShouldMovePlayerLeftWithLeft();
    void keyDownShouldNotMovePlayerRightWithLeftKey();
    void keyDownShouldMovePlayerRightWithRightKey();
    void keyDownShouldNorMovePlayerLeftWithRightKey();
    void keyDownShouldMakePlayerJumpWithUpKey();
    void keyDownShouldHandleJumpAndMoveAtSameTime();
    void keyUpShouldStopMovement();

private:
    InputHandler *i;
    SnoopyMessaging *m;
    SnoopySprite *snoopy;

};


#endif // TESTINPUTHANDLER_H
