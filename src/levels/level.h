#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "spoonymessaging.h"
#include "level.h"
#include "soundhandler.h"

class SpoonySprite;
class QGraphicsObject;

class Level : public QObject
{
    Q_OBJECT
public:
    Level(QGraphicsScene *_scene, SpoonyMessage *m,
          SoundHandler *sound, QTimer *_timer, QObject *parent = 0);
    ~Level();

    virtual void play() = 0;

    SpoonySprite *spoony;
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
