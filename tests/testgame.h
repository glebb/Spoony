#ifndef TESTGAME_H
#define TESTGAME_H

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

    void resetLeveShouldCreateLevelAgainOnReset();
    void restartGameShouldSetLivesToDefault();
    void restartGameShouldSetRoundToOne();
    void restartGameShouldSetLevelToOne();
    void nextLevelshouldChangeCurrentLevel();
    void onDieShouldReduceLivesByOne();
    void getCurrentLevelShouldBeOneOnStart();
    void getRoundShouldBeOneOnStart();

private:
    Game *game;
    FakeLevel *level;
    SnoopyMessaging *m;
    QTimer *timer;

};
#endif // TESTGAME_H
