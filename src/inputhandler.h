#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QKeyEvent>

class SnoopySprite;


class InputHandler : public QObject
{
    Q_OBJECT
public:
    InputHandler();
    ~InputHandler();

    bool keyDown(SnoopySprite *snoopy, const QKeyEvent *event);
    bool keyUp(SnoopySprite *snoopy, const QKeyEvent *event);

signals:
    void jump();

private:
    bool _up;
    bool _leftPressed;
    bool _rightPressed;
};

#endif // INPUTHANDLER_H
