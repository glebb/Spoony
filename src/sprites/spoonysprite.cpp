#include "spoonysprite.h"

#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QCoreApplication>

#include "standingstate.h"
#include "runningstate.h"
#include "jumpingstate.h"
#include "spoonymessaging.h"
#include "globals.h"

const int SpoonySprite::spriteWidth = 56;
const int SpoonySprite::spriteHeight = 90;

SpoonySprite::SpoonySprite(SpoonyMessage *m, SoundHandler *sound, QGraphicsItem * parent)
    :QGraphicsObject(parent), m(m), _sound(sound)
{
    _mSpriteImage = new QPixmap(":/images/tux_from_linux.png");

    StandingState* standing = new StandingState(this);
    RunningState* running = new RunningState(this);
    JumpingState* jumping = new JumpingState(this);
    standing->addTransition(this,SIGNAL(jump()),jumping);
    standing->addTransition(this,SIGNAL(buttonDown()),running);
    running->addTransition(this,SIGNAL(jump()),jumping);
    running->addTransition(this,SIGNAL(buttonUp()),standing);
    running->addTransition(this,SIGNAL(die()),standing);
    jumping->addTransition(&this->move,SIGNAL(landed()), standing);
    standing->addTransition(&this->move,SIGNAL(movingAfterLanding()), running);

    _stateMachine.addState(standing);
    _stateMachine.addState(running);
    _stateMachine.addState(jumping);

    _stateMachine.setInitialState(standing);
    _stateMachine.start();

    move.setSpoony(this);

    dying = false;
    connect(this,SIGNAL(die()), m, SLOT(onDie()));
    connect(&_input, SIGNAL(jump()), SLOT(playJumpSound()));

    _x = 0;
    _y = 0;

    setObjectName("SpoonySprite");
}

void SpoonySprite::keyPressEvent(QKeyEvent *event)
{

    if (!dying && _input.keyDown(this, event))
        emit buttonDown();
}

void SpoonySprite::keyReleaseEvent(QKeyEvent *event)
{
    if (_input.keyUp(this, event))
        emit buttonUp();
}

SpoonySprite::~SpoonySprite()
{
    delete _mSpriteImage;
}

QRectF SpoonySprite::boundingRect() const
{
    return QRectF(8,18, spriteWidth-16, spriteHeight-30);
}

void SpoonySprite::paint(QPainter* painter, const QStyleOptionGraphicsItem*/*option*/,QWidget*/*widget*/)
{
    painter->drawPixmap(0,0,*_mSpriteImage, _x*spriteWidth, _y*spriteHeight, spriteWidth, spriteHeight);
//    painter->drawPath(shape());
//    painter->drawRect(boundingRect());
}

void SpoonySprite::nextFrame()
{
    emit tick();
    this->update();
}

void SpoonySprite::onDie()
{
    emit die();
}

void SpoonySprite::onJump()
{
    emit jump();
}

void SpoonySprite::onLand()
{
    emit buttonDown();
}

QPainterPath SpoonySprite::shape() const
{
    QRectF r = boundingRect();
    QPainterPath path;
    path.addEllipse(r);
    return path;
}

void SpoonySprite::playJumpSound()
{
    _sound->playSound("/sounds/jump.wav");
}

void SpoonySprite::playDeathSound()
{
    _sound->playSound("/sounds/falling.wav");
}
