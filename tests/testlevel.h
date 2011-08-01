#ifndef TST_TESTLEVEL_H
#define TST_TESTLEVEL_H

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
    void shouldKillPlayerWhenCollidingWithKiller();
    void shouldNotKillPlayerWhenCollidingNormalObject();
    void shouldNotKillPlayerWhenNotCollidingWithKiller();
    void shouldNotKillPlayerWhenNotCollidingWithNormalObject();

private:
    QGraphicsScene *scene;
    SnoopyMessaging *m;
    QTimer *t;
    Level1 *l;
    FakeGraphics *gfx2;

};

#endif // TST_TESTLEVEL_H
