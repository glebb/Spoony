#include "game.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <qdeclarativeengine.h>
#include <qdeclarativecomponent.h>
#include <qdeclarativecontext.h>
#include <qdeclarativeitem.h>

#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "globals.h"


Game::Game(QObject *parent) : QObject(parent)
{
    _m = new SnoopyMessaging(this);
    timer = new QTimer(this);
    _speed = DEFAULT_SPEED;
    timer->start(1000 / _speed);
    _scene = new QGraphicsScene(0, 0, WIDTH, HEIGHT);
    _view = new QGraphicsView(_scene);
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setRenderHint(QPainter::Antialiasing);
    _view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    _view->setCacheMode(QGraphicsView::CacheBackground);
    _currentLevel = 0;
    connect(_m, SIGNAL(finish()), this, SLOT(nextLevel()));
    connect(_m, SIGNAL(reset()), this, SLOT(onDie()));
    _engine = new QDeclarativeEngine(this);
    _engine->rootContext()->setContextProperty("Game", this);
    _component = new QDeclarativeComponent(_engine, QUrl("qrc:///startscreen.qml"));
    _component->setObjectName("Startup");
    _sound = new SoundHandler(this);
    _lives = LIVES;
    emit ready();
}

Game::~Game()
{
    if (_currentLevel != 0)
        delete _currentLevel;
}

void Game::start(int lives, int level)
{
    // qDebug() << "start game";
    _clearScreen();
    this->_lives = lives;
    _rounds = 1;
    _currentLevelNr = level;
    _createLevel(_currentLevelNr);
    _currentLevel->play();
}

void Game::onDie()
{
    _lives--;
    // qDebug() << "die" << lives;

    if (_lives == 0)
        restartGame();
    else
        resetLevel();
}

void Game::nextLevel()
{
    // qDebug() << "nextlevel";
    _currentLevelNr++;
    _createLevel(_currentLevelNr);
    _currentLevel->play();
}

void Game::_createLevel(int nr)
{
    if (_currentLevel != 0) {
        delete _currentLevel;
    }

    _clearScreen();
    _currentLevelNr = nr;
    switch (nr)
    {
        case 1:
            _currentLevel = new Level1(_scene, _m, _sound, timer, this);
            break;
        case 2:
            _currentLevel = new Level3(_scene, _m, _sound, timer, this);
            break;
        case 3:
            _currentLevel = new Level2(_scene, _m, _sound, timer, this);
            break;
        case 4:
            _currentLevel = new Level4(_scene, _m, _sound, timer, this);
            break;

        default: // Start from beginning
                _currentLevel = new Level1(_scene, _m, _sound, timer, this);
                _currentLevelNr = 1;
                _rounds++;
                if (_speed < 120)
                    _speed += _speed / 3;
                timer->stop();
                timer->start(1000 / _speed);
                break;
    }
    _text = new QGraphicsSimpleTextItem();
    _text->setText("LIVES:  " + QString::number(_lives) + " LEVEL " + QString::number(_currentLevelNr) + ":  " + _currentLevel->getName());
    _text->font().setBold(true);
    _scene->addItem(_text);
    _text->setPos(20, 10);
    // qDebug() << "created level" << currentLevelNr;

}

void Game::restartGame()
{
    // qDebug() << "restart game";
    _lives = LIVES;
    _speed = DEFAULT_SPEED;
    timer->stop();
    timer->start(1000 / _speed);
    showStartupScreen();
}

void Game::initializeGame()
{
    // qDebug() << "initialize game";
    _rounds = 1;
    _currentLevelNr = 1;
    _view->show();
}

void Game::setCurrentLevel(int level)
{
    _currentLevelNr = level;
    resetLevel();
}

void Game::setCurrentLevel(Level *level)
{
    _currentLevel = level;
}

void Game::resetLevel()
{
    // qDebug() << "reset level";
    _createLevel(_currentLevelNr);
    _currentLevel->play();
}

void Game::showStartupScreen()
{
    _clearScreen();

    if (_component->isLoading())
    {
        QObject::connect(_component, SIGNAL(statusChanged(QDeclarativeComponent::Status)),
                         this, SLOT(continueLoading()));
    }
    else continueLoading();
}

void Game::continueLoading()
{
    if (_component->isError())
    {
        qWarning() << _component->errors();
    }
    else
    {
        _item = qobject_cast<QDeclarativeItem *>(_component->create());
        _scene->addItem(_item);
        _item->grabKeyboard();
    }
}

void Game::_clearScreen()
{
    // Let's keep the startupscreen existing
    if (_scene->items().contains(_item))
        _scene->removeItem(_item);
    _scene->clear(); // Everything else can go.
}
