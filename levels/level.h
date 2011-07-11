#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "snoopymessaging.h"
#include "level.h"
#include "soundhandler.h"

class SnoopySprite;
class QGraphicsObject;

class Level : public QObject
{
    Q_OBJECT
public:
    Level(QGraphicsScene *_scene, SnoopyMessaging *m,
          SoundHandler *sound, QTimer *_timer, QObject *parent = 0);
    ~Level();

    virtual void play() = 0;

    SnoopySprite *snoopy;
    void addKillObjects(QGraphicsObject *obj);
    QString getName() { return _name; }

signals:
    void die();

public slots:
    void onCollide();

protected:
    QList<QGraphicsItem *> killers;

    QGraphicsScene *_scene;
    QTimer *_timer;
    QString _name;


};

#endif // LEVEL_H
