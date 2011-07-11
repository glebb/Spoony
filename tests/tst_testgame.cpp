#include "tst_testgame.h"

#include "game.h"
#include "fakelevel.h"
#include "fakegraphics.h"
#include "snoopymessaging.h"
#include "globals.h"

#include <QtTest/QtTest>

TestGame::TestGame()
{
}

void TestGame::init()
{
    m = new SnoopyMessaging;
    timer = new QTimer;
    level = new FakeLevel(0, m, new FakeSoundHandler, timer);
    game = new Game();

}

void TestGame::cleanup()
{
    delete m;
    delete timer;
    delete game;
}

void TestGame::testRoundIsOneOnStartGame()
{
    game->setCurrentLevel(level);
    game->start(3);
    QCOMPARE(game->getRound(), 1);
}

void TestGame::testCurrentLevelIsOneOnStart()
{
    game->setCurrentLevel(level);
    game->start(3);
    QCOMPARE(1, game->getCurrentLevelNr());
}

void TestGame::testLivesIsReducedOnDeath()
{
    game->start(3);
    game->onDie();
    QCOMPARE(2, game->getLives());
}

void TestGame::testLevelChangesOnLevelChange()
{
    game->setCurrentLevel(level);
    game->nextLevel();
    QVERIFY(level != game->getCurrentLevel());
}

void TestGame::testRestartRestartsFromLevelOne()
{
    game->setCurrentLevel(level);
    game->start(3);
    game->onDie();
    game->restartGame();
    QCOMPARE(1, game->getRound());
    QCOMPARE(1, game->getCurrentLevelNr());
    QCOMPARE(LIVES, game->getLives());
}

void TestGame::testResetLevelCreatesLevelAgain()
{
    game->resetLevel();
    QVERIFY(level != game->getCurrentLevel());

}
