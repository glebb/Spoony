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
    messaging = new SpoonyMessage();
    timer = new QTimer();
    level = new Level1(scene, messaging, new FakeSoundHandler, timer);
    fakeGraphics = new FakeGraphics;
    level->play();
}


void LevelSpec::cleanup()
{
    delete scene;
    delete messaging;
    delete timer;
    delete level;
}

void LevelSpec::onCollideShouldKillPlayerWhenCollidingWithKiller()
{
    QRectF r(DEFAULT_START_POSITION.x(), DEFAULT_START_POSITION.y(), 300, 300); // Same location as Spoony
    fakeGraphics->setBounds(r);
    scene->addItem(fakeGraphics);

    level->addKillObjects(fakeGraphics);

    QSignalSpy stateSpy(level, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    level->onCollide();
    QCOMPARE(stateSpy.count(), 1);
}

void LevelSpec::onCollideShouldNotKillPlayerWhenCollidingNormalObject()
{

    QRectF r(DEFAULT_START_POSITION.x(), DEFAULT_START_POSITION.y(), 300, 300); // Same location as Spoony
    fakeGraphics->setBounds(r);
    scene->addItem(fakeGraphics);
    QSignalSpy stateSpy(level, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    level->onCollide();
    QCOMPARE(stateSpy.count(), 0);}

void LevelSpec::onCollideShouldNotKillPlayerWhenNotCollidingWithKiller()
{
    QRectF r(0, 0, 10, 10);
    fakeGraphics->setBounds(r);
    scene->addItem(fakeGraphics);

    level->addKillObjects(fakeGraphics);

    QSignalSpy stateSpy(level, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    level->onCollide();
    QCOMPARE(stateSpy.count(), 0);
}

void LevelSpec::onCollideShouldNotKillPlayerWhenNotCollidingWithNormalObject()
{
    QRectF r(0, 0, 10, 10);
    fakeGraphics->setBounds(r);
    scene->addItem(fakeGraphics);

    QSignalSpy stateSpy(level, SIGNAL(die()));
    QVERIFY(stateSpy.isValid());
    QCOMPARE(stateSpy.count(), 0);
    level->onCollide();
    QCOMPARE(stateSpy.count(), 0);
}
