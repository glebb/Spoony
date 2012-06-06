#include "movehandler.h"
#include "spoonysprite.h"
#include "spoonymessaging.h"
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
        item->setPos(item->pos().x() - _spoony->spriteWidth, item->pos().y());
        goingLeft = false;
        goingRight = true;
    }
    else {
        item->setPos(item->pos().x() + _spoony->spriteWidth, item->pos().y());
        goingLeft = true;
        goingRight = false;
    }
}

void MoveHandler::moveSpoony()
{
    if (_spoony->dying) {
        emit die();
        return;
    }
    if (jumping) {
        emit jump();
        if (jumpHeightControl < 14)
        {
            _spoony->setPos(_spoony->pos().x(), _spoony->pos().y() - 6);
            jumpHeightControl++;
        }
        else {
            _spoony->setPos(_spoony->pos().x(), _spoony->pos().y() + 6);
        }
    }
    int colliding = _spoony->collidingItems().size();
    foreach(QGraphicsItem *i,_spoony->collidingItems())
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
            while (_spoony->collidingItems().size() == colliding)
            {
                _spoony->setPos(_spoony->pos().x(), _spoony->pos().y() - 1);
            }
            _spoony->setPos(_spoony->pos().x(), _spoony->pos().y() + 1);
            break;
        }
        _spoony->setPos(_spoony->pos().x(), _spoony->pos().y() + 6);
    }
    if (!jumping && _spoony->collidingItems().size() == 0)
        _spoony->setPos(_spoony->pos().x(), _spoony->pos().y() + 6);

    if (moving)
    {
        int dir = 0;
        if (goingLeft && _spoony->pos().x() >= _spoony->spriteWidth / 2) dir = -6;
        if (goingRight) dir = 6;
        _spoony->setPos(_spoony->pos().x() + dir, _spoony->pos().y());
    }

    if (_spoony->collidingItems().size() > 0) emit collides();

    if (goingRight && _spoony->pos().x() + _spoony->spriteWidth / 2 >= WIDTH){
        emit finished();
        return;
    }
    if (goingLeft && _spoony->pos().x()  - _spoony->spriteWidth / 2 >= WIDTH){
        emit finished();
        return;
    }

}

void MoveHandler::setSpoony(SpoonySprite *spoony)
{
    this->_spoony = spoony;
    connect(this,SIGNAL(die()), spoony, SLOT(onDie()));
    connect(this,SIGNAL(jump()), spoony, SLOT(onJump()));
    connect(this,SIGNAL(landed()), spoony, SLOT(onLand()));

    connect(this,SIGNAL(finished()), spoony->m, SLOT(onFinish()));
    connect(this,SIGNAL(collides()), spoony->m, SLOT(onCollide()));
    connect(this,SIGNAL(finishedDying()), spoony->m,SLOT(onResetLevel()));

}

void MoveHandler::death()
{
    _spoony->dying = true;

    _spoony->setPos(_spoony->pos().x(), _spoony->pos().y() + 2);
    moving = false;

    // Put back to start position
    if (_spoony->pos().y() > HEIGHT) {
        _spoony->dying = false;
        if (goingLeft) {
            changeDir(_spoony);
            goingLeft = false;
            goingRight = true;
        }
        _spoony->setPos(DEFAULT_START_POSITION);
        emit finishedDying();
    }
}

void MoveHandler::reset()
{
    jumping = false;
    emit landed();
}
