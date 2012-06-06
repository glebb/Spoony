#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QKeyEvent>

class SpoonySprite;


class InputHandler : public QObject
{
    Q_OBJECT
public:
    InputHandler();
    ~InputHandler();

    bool keyDown(SpoonySprite *spoony, const QKeyEvent *event);
    bool keyUp(SpoonySprite *spoony, const QKeyEvent *event);

signals:
    void jump();

private:
    bool _up;
    bool _leftPressed;
    bool _rightPressed;
};

#endif // INPUTHANDLER_H
