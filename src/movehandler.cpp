#include "movehandler.h"
#include "snoopysprite.h"
#include "snoopymessaging.h"
#include "globals.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QPointF>

#include "basicsprite.h"


MoveHandler::MoveHandler()
{
    jumpHeightControl = 0;
    jumping = false;
    moving = false;
    goingLeft = false;
    goingRight = true;

    connect(this, SIGNAL(die()), this,SLOT(death()));
}

MoveHandler::~MoveHandler()
{
}

void MoveHandler::changeDir(QGraphicsItem* item)
{
    item->scale(-1, 1);
    if (goingLeft)
    {
        item->setPos(item->pos().x() - _snoopy->spriteWidth, item->pos().y());
        goingLeft = false;
        goingRight = true;
    }
    else {
        item->setPos(item->pos().x() + _snoopy->spriteWidth, item->pos().y());
        goingLeft = true;
        goingRight = false;
    }
}

void MoveHandler::moveSnoopy()
{
    if (_snoopy->dying) {
        emit die();
        return;
    }
    if (jumping) {
        emit jump();
        if (jumpHeightControl < 14)
        {
            _snoopy->setPos(_snoopy->pos().x(), _snoopy->pos().y() - 6);
            jumpHeightControl++;
        }
        else {
            _snoopy->setPos(_snoopy->pos().x(), _snoopy->pos().y() + 6);
        }
    }
    int colliding = _snoopy->collidingItems().size();
    foreach(QGraphicsItem *i,_snoopy->collidingItems())
    {
        BasicSprite *s = qgraphicsitem_cast<BasicSprite *>(i);
        if (s->isSolidPlane()) {
            if (jumping)
            {
                emit landed();
                jumping = false;
                jumpHeightControl = 0;
                if (moving) emit movingAfterLanding();
            }
            // Correct y
            while (_snoopy->collidingItems().size() == colliding)
            {
                _snoopy->setPos(_snoopy->pos().x(), _snoopy->pos().y() - 1);
            }
            _snoopy->setPos(_snoopy->pos().x(), _snoopy->pos().y() + 1);
            break;
        }
        _snoopy->setPos(_snoopy->pos().x(), _snoopy->pos().y() + 6);
    }
    if (!jumping && _snoopy->collidingItems().size() == 0)
        _snoopy->setPos(_snoopy->pos().x(), _snoopy->pos().y() + 6);

    if (moving)
    {
        int dir = 0;
        if (goingLeft && _snoopy->pos().x() >= _snoopy->spriteWidth / 2) dir = -6;
        if (goingRight) dir = 6;
        _snoopy->setPos(_snoopy->pos().x() + dir, _snoopy->pos().y());
    }

    if (_snoopy->collidingItems().size() > 0) emit collides();

    if (goingRight && _snoopy->pos().x() + _snoopy->spriteWidth / 2 >= WIDTH){
        emit finished();
        return;
    }
    if (goingLeft && _snoopy->pos().x()  - _snoopy->spriteWidth / 2 >= WIDTH){
        emit finished();
        return;
    }

}

void MoveHandler::setSnoopy(SnoopySprite *snoopy)
{
    this->_snoopy = snoopy;
    connect(this,SIGNAL(die()), snoopy, SLOT(onDie()));
    connect(this,SIGNAL(jump()), snoopy, SLOT(onJump()));
    connect(this,SIGNAL(landed()), snoopy, SLOT(onLand()));

    connect(this,SIGNAL(finished()), snoopy->m, SLOT(onFinish()));
    connect(this,SIGNAL(collides()), snoopy->m, SLOT(onCollide()));
    connect(this,SIGNAL(finishedDying()), snoopy->m,SLOT(onResetLevel()));

}

void MoveHandler::death()
{
    _snoopy->dying = true;

    _snoopy->setPos(_snoopy->pos().x(), _snoopy->pos().y() + 2);
    moving = false;

    // Put back to start position
    if (_snoopy->pos().y() > HEIGHT) {
        _snoopy->dying = false;
        if (goingLeft) {
            changeDir(_snoopy);
            goingLeft = false;
            goingRight = true;
        }
        _snoopy->setPos(DEFAULT_START_POSITION);
        emit finishedDying();
    }
}

void MoveHandler::reset()
{
    jumping = false;
    emit landed();
}
