#ifndef MOVEHANDLER_H
#define MOVEHANDLER_H

#include <QGraphicsItem>
#include <QTimer>



class SnoopySprite;

class MoveHandler :  public QObject
{
    Q_OBJECT
public:
    MoveHandler();
    ~MoveHandler();
    void setSnoopy(SnoopySprite *_snoopy);

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
    void moveSnoopy();
    void death();

private:
    SnoopySprite *_snoopy;
};

#endif // MOVEHANDLER_H
