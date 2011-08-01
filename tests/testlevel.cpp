#include "testlevel.h"

#include "level1.h"
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QtTest/QtTest>

#include "fakegraphics.h"
#include "globals.h"

LevelSpec::LevelSpec()
{
}

void LevelSpec::init()
{
    scene = new QGraphicsScene(0,0, 1000, 1000);
    m = new SnoopyMessaging();
    t = new QTimer();
    l = new Level1(scene, m, new FakeSoundHandler, t);
    gfx2 = new FakeGraphics;
    l->play();
}


void LevelSpec::cleanup()
{
    delete scene;
    delete m;
    delete t;
    delete l;
}

void LevelSpec::shouldKillPlayerWhenCollidingWithKiller()
{
    QRectF r(DEFAULT_START_POSITION.x(), DEFAULT_START_POSITION.y(), 300, 300); // Same location as Snoopy
    gfx2->setBounds(r);
    scene->addItem(gfx2);

    l->addKillObjects(gfx2);

    QSignalSpy stateSpy(l, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    l->onCollide();
    QCOMPARE(stateSpy.count(), 1);
}

void LevelSpec::shouldNotKillPlayerWhenCollidingNormalObject()
{

    QRectF r(DEFAULT_START_POSITION.x(), DEFAULT_START_POSITION.y(), 300, 300); // Same location as Snoopy
    gfx2->setBounds(r);
    scene->addItem(gfx2);
    QSignalSpy stateSpy(l, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    l->onCollide();
    QCOMPARE(stateSpy.count(), 0);}

void LevelSpec::shouldNotKillPlayerWhenNotCollidingWithKiller()
{
    QRectF r(0, 0, 10, 10);
    gfx2->setBounds(r);
    scene->addItem(gfx2);

    l->addKillObjects(gfx2);

    QSignalSpy stateSpy(l, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    l->onCollide();
    QCOMPARE(stateSpy.count(), 0);
}

void LevelSpec::shouldNotKillPlayerWhenNotCollidingWithNormalObject()
{
    QRectF r(0, 0, 10, 10);
    gfx2->setBounds(r);
    scene->addItem(gfx2);

    QSignalSpy stateSpy(l, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    l->onCollide();
    QCOMPARE(stateSpy.count(), 0);
}
