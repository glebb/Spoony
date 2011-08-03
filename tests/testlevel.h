#ifndef TESTLEVEL_H
#define TESTLEVEL_H

#include <QtTest/QtTest>

class QGraphicsScene;
class SnoopyMessaging;
class Level1;
class FakeGraphics;

class LevelSpec : public QObject
{
    Q_OBJECT

public:
    LevelSpec();

private Q_SLOTS:
    void init();
    void cleanup();
    void onCollideShouldKillPlayerWhenCollidingWithKiller();
    void onCollideShouldNotKillPlayerWhenCollidingNormalObject();
    void onCollideShouldNotKillPlayerWhenNotCollidingWithKiller();
    void onCollideShouldNotKillPlayerWhenNotCollidingWithNormalObject();

private:
    QGraphicsScene *scene;
    SnoopyMessaging *messaging;
    QTimer *timer;
    Level1 *level;
    FakeGraphics *fakeGraphics;

};

#endif // TESTLEVEL_H
