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

void GameSpec::shouldBeRoundOneOnStart()
{
    game->setCurrentLevel(level);
    game->start(3);
    QCOMPARE(game->getRound(), 1);
}

void GameSpec::shouldStartOnLevelOne()
{
    game->setCurrentLevel(level);
    game->start(3);
    QCOMPARE(1, game->getCurrentLevelNr());
}

void GameSpec::shouldReduceLivesOnDeath()
{
    game->start(3);
    game->onDie();
    QCOMPARE(2, game->getLives());
}

void GameSpec::shouldChangeCurrentLevel()
{
    game->setCurrentLevel(level);
    game->nextLevel();
    QVERIFY(level != game->getCurrentLevel());
}

void GameSpec::shouldStartOnLevelOneOnRestart()
{
    game->setCurrentLevel(level);
    game->start(3);
    game->onDie();
    game->restartGame();
    QCOMPARE(1, game->getRound());
    QCOMPARE(1, game->getCurrentLevelNr());
    QCOMPARE(LIVES, game->getLives());
}

void GameSpec::shouldCreateLevelAgainOnReset()
{
    game->resetLevel();
    QVERIFY(level != game->getCurrentLevel());

}
