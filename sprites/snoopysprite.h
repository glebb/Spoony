#ifndef SNOOPYSPRITE_H
#define SNOOPYSPRITE_H

#include <QPoint>
#include <QPixmap>
#include <QGraphicsObject>
#include <QStateMachine>
#include <QTimer>

#include "movehandler.h"
#include "inputhandler.h"
#include "soundhandler.h"

class SnoopyMessage;

class QPainter;

class SnoopySprite: public QGraphicsObject
{
    Q_OBJECT
public:

    SnoopySprite(SnoopyMessage *m, SoundHandler *_sound, QGraphicsItem * parent = 0);

    ~SnoopySprite();

    const static int spriteWidth;
    const static int spriteHeight;

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/,QWidget */*widget*/);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    QPainterPath shape() const;

    bool dying;
    MoveHandler move;

    SnoopyMessage *m;



public slots:
    void onDie();
    void onJump();
    void onLand();
    void playJumpSound();
    void playDeathSound();

private slots:
    void nextFrame();

signals:
    void tick();
    void buttonDown();
    void buttonUp();
    void die();
    void jump();

private:
    InputHandler _input;
    QPixmap* _mSpriteImage;
    int _x;
    int _y;
    QStateMachine _stateMachine;

    friend class RunningState;
    friend class StandingState;
    friend class JumpingState;

    QTimer *_timer;
    SoundHandler *_sound;

};

#endif // SNOOPYSPRITE_H
