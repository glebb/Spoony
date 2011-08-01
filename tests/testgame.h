#ifndef TST_TESTGAME_H
#define TST_TESTGAME_H

#include <QtTest/QtTest>

class Game;
class FakeLevel;
class SnoopyMessaging;
class QTimer;

class GameSpec : public QObject
{
    Q_OBJECT

public:
    GameSpec();

private Q_SLOTS:
    void init();
    void cleanup();
    void shouldStartOnLevelOne();
    void shouldBeRoundOneOnStart();
    void shouldReduceLivesOnDeath();
    void shouldChangeCurrentLevel();
    void shouldStartOnLevelOneOnRestart();
    void shouldCreateLevelAgainOnReset();

private:
    Game *game;
    FakeLevel *level;
    SnoopyMessaging *m;
    QTimer *timer;

};
#endif // TST_TESTGAME_H
