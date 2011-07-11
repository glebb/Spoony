#ifndef TST_TESTLEVEL_H
#define TST_TESTLEVEL_H

#include <QtTest/QtTest>

class QGraphicsScene;
class SnoopyMessaging;
class Level1;
class FakeGraphics;

class TestLevel : public QObject
{
    Q_OBJECT

public:
    TestLevel();

private Q_SLOTS:
    void init();
    void cleanup();
    void testCollidingWithKillerKillsSnoopy();
    void testCollidingWithNormalDoesntKill();
    void testNotCollidingWithKillerDoesntKill();
    void testNotCollidingWithNormalDoesntKill();

private:
    QGraphicsScene *scene;
    SnoopyMessaging *m;
    QTimer *t;
    Level1 *l;
    FakeGraphics *gfx2;

};

#endif // TST_TESTLEVEL_H
