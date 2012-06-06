#ifndef TESTINPUTHANDLER_H
#define TESTINPUTHANDLER_H

#include <QtTest/QtTest>

class InputHandler;
class SpoonyMessage;
class SpoonySprite;

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
    SpoonyMessage *m;
    SpoonySprite *spoony;

};


#endif // TESTINPUTHANDLER_H
