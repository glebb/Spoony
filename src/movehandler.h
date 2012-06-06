#ifndef MOVEHANDLER_H
#define MOVEHANDLER_H

#include <QGraphicsItem>
#include <QTimer>



class SpoonySprite;

class MoveHandler :  public QObject
{
    Q_OBJECT
public:
    MoveHandler();
    ~MoveHandler();
    void setSpoony(SpoonySprite *_spoony);

    void changeDir(QGraphicsItem* item);
    bool jumping;
    bool moving;
    bool goingLeft;
    bool goingRight;

    int jumpHeightControl;

    void reset();

signals:
    void die();
    void jump();
    void landed();
    void finished();
    void gameOver();
    void collides();
    void finishedDying();
    void movingAfterLanding();


public slots:
    void moveSpoony();
    void death();

private:
    SpoonySprite *_spoony;
};

#endif // MOVEHANDLER_H
