#include "testgame.h"

#include "game.h"
#include "fakelevel.h"
#include "fakegraphics.h"
#include "snoopymessaging.h"
#include "globals.h"

#include <QtTest/QtTest>

GameSpec::GameSpec()
{
}

void GameSpec::init()
{
    m = new SnoopyMessaging;
    timer = new QTimer;
    level = new FakeLevel(0, m, new FakeSoundHandler, timer);
    game = new Game();

}

void GameSpec::cleanup()
{
    delete m;
    delete timer;
    delete game;
}

void GameSpec::getRoundShouldBeOneOnStart()
{
    game->setCurrentLevel(level);
    game->start(3);
    int round = game->getRound();
    QCOMPARE(round, 1);
}

void GameSpec::getCurrentLevelShouldBeOneOnStart()
{
    game->setCurrentLevel(level);
    game->start(3);
    int level = game->getCurrentLevelNr();
    QCOMPARE(1, level);
}

void GameSpec::onDieShouldReduceLivesByOne()
{
    game->start(3);
    int original_lives = game->getLives();
    game->onDie();
    int lives = game->getLives();
    QCOMPARE(original_lives - 1, lives);
}

void GameSpec::nextLevelshouldChangeCurrentLevel()
{
    game->setCurrentLevel(level);
    game->nextLevel();
    Level *current_level = game->getCurrentLevel();
    QVERIFY(level != current_level);
}

void GameSpec::restartGameShouldSetLevelToOne()
{
    game->setCurrentLevel(level);
    game->start(3);
    game->onDie();
    game->restartGame();
    int level = game->getCurrentLevelNr();
    QCOMPARE(1, level);
}

void GameSpec::restartGameShouldSetRoundToOne()
{
    game->setCurrentLevel(level);
    game->start(3);
    game->onDie();
    game->restartGame();
    int round = game->getRound();
    QCOMPARE(1, round);
}

void GameSpec::restartGameShouldSetLivesToDefault()
{
    game->setCurrentLevel(level);
    game->start(3);
    game->onDie();
    game->restartGame();
    int current_lives = game->getLives();
    QCOMPARE(LIVES, current_lives);
}


void GameSpec::resetLeveShouldCreateLevelAgainOnReset()
{
    game->resetLevel();
    Level *current_level = game->getCurrentLevel();
    QVERIFY(level != current_level);

}
