#ifndef TST_TESTGAME_H
#define TST_TESTGAME_H

#include <QtTest/QtTest>

class Game;
class FakeLevel;
class SnoopyMessaging;
class QTimer;

class TestGame : public QObject
{
    Q_OBJECT

public:
    TestGame();

private Q_SLOTS:
    void init();
    void cleanup();
    void testRoundIsOneOnStartGame();
    void testCurrentLevelIsOneOnStart();
    void testLivesIsReducedOnDeath();
    void testLevelChangesOnLevelChange();
    void testRestartRestartsFromLevelOne();
    void testResetLevelCreatesLevelAgain();

private:
    Game *game;
    FakeLevel *level;
    SnoopyMessaging *m;
    QTimer *timer;

};
#endif // TST_TESTGAME_H
