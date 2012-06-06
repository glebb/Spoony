#include "snoopysprite.h"

#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QCoreApplication>

#include "standingstate.h"
#include "runningstate.h"
#include "jumpingstate.h"
#include "snoopymessaging.h"
#include "globals.h"

const int SnoopySprite::spriteWidth = 121;
const int SnoopySprite::spriteHeight = 150;

SnoopySprite::SnoopySprite(SnoopyMessage *m, SoundHandler *sound, QGraphicsItem * parent)
    :QGraphicsObject(parent), m(m), _sound(sound)
{
    _mSpriteImage = new QPixmap(":/images/snoopy.png");

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

    move.setSnoopy(this);

    dying = false;
    connect(this,SIGNAL(die()), m, SLOT(onDie()));
    connect(&_input, SIGNAL(jump()), SLOT(playJumpSound()));

    _x = 0;
    _y = 0;

    setObjectName("SnoopySprite");
}

void SnoopySprite::keyPressEvent(QKeyEvent *event)
{

    if (!dying && _input.keyDown(this, event))
        emit buttonDown();
}

void SnoopySprite::keyReleaseEvent(QKeyEvent *event)
{
    if (_input.keyUp(this, event))
        emit buttonUp();
}

SnoopySprite::~SnoopySprite()
{    
    delete _mSpriteImage;
}

QRectF SnoopySprite::boundingRect() const
{
    return QRectF(0,7,spriteWidth, spriteHeight);
}

void SnoopySprite::paint(QPainter* painter, const QStyleOptionGraphicsItem*/*option*/,QWidget*/*widget*/)
{
    painter->drawPixmap(0,0,*_mSpriteImage, _x*spriteWidth, _y*spriteHeight, spriteWidth, spriteHeight);
//    painter->drawPath(shape());
    //painter->drawRect(0,0,spriteWidth,spriteHeight);
}

void SnoopySprite::nextFrame()
{
    emit tick();
    this->update();
}

void SnoopySprite::onDie()
{
    emit die();
}

void SnoopySprite::onJump()
{
    emit jump();
}

void SnoopySprite::onLand()
{
    emit buttonDown();
}

QPainterPath SnoopySprite::shape() const
{
    QRectF r = boundingRect();
    r.adjust(20,6,-20,-6);
    QPainterPath path;
    path.addEllipse(r);
    return path;
}

void SnoopySprite::playJumpSound()
{
    _sound->playSound("/sounds/jump.wav");
}

void SnoopySprite::playDeathSound()
{
    _sound->playSound("/sounds/falling.wav");
}
