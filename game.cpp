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
#include "levelfactory.h"
#include "globals.h"



Game::Game(QObject *parent) : QObject(parent)
{
    snoopy_message = new SnoopyMessage(this);
    global_timer = new QTimer(this);
    global_speed = DEFAULT_SPEED;
    global_timer->start(1000 / global_speed);
    main_scene = new QGraphicsScene(0, 0, WIDTH, HEIGHT);
    main_view = new QGraphicsView(main_scene);
    main_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    main_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    main_view->setRenderHint(QPainter::Antialiasing);
    main_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    main_view->setCacheMode(QGraphicsView::CacheBackground);
    current_level = 0;
    connect(snoopy_message, SIGNAL(finish()), this, SLOT(playNextLevel()));
    connect(snoopy_message, SIGNAL(reset()), this, SLOT(onDie()));
    qml_engine = new QDeclarativeEngine(this);
    qml_engine->rootContext()->setContextProperty("Game", this);
    qml_startscreen = new QDeclarativeComponent(qml_engine, QUrl("qrc:///startscreen.qml"));
    qml_startscreen->setObjectName("Startup");
    sound_handler = new SoundHandler(this);
    global_lives = LIVES;
    emit ready();
}

Game::~Game()
{
    if (current_level != 0)
        delete current_level;
}

void Game::start(int lives, int level)
{
    clearGfxObjectsFromScene();
    this->global_lives = lives;
    gamerounds_completed = 0;
    this->level = level;
    create_level();
    current_level->play();
}

void Game::playNextLevel()
{
    // qDebug() << "nextlevel";
    level++;
    create_level();
    current_level->play();
}

void Game::setupScene()
{
    clearGfxObjectsFromScene();
    lives_text = new QGraphicsSimpleTextItem();
    lives_text->setText("LIVES:  " + QString::number(global_lives) + " LEVEL " + QString::number(level) + ":  " + current_level->getName());
    lives_text->font().setBold(true);
    main_scene->addItem(lives_text);
    lives_text->setPos(20, 10);
}

void Game::restartGame()
{
    global_lives = LIVES;
    global_speed = DEFAULT_SPEED;
    global_timer->stop();
    global_timer->start(1000 / global_speed);
    showStartupScreen();
}

void Game::initializeGame()
{
    gamerounds_completed = 0;
    level = 1;
    main_view->show();
}

void Game::onDie()
{
    //TODO: Exercise 4 //Optional
    global_lives--;

    if (global_lives == 0)
        restartGame();
    else
        resetLevel();
}


void Game::setCurrentLevel(int level)
{
    this->level = level;
    resetLevel();
}

void Game::setCurrentLevel(Level *level)
{
    current_level = level;
}

void Game::resetLevel()
{
    create_level();
    current_level->play();
}

void Game::showStartupScreen()
{
    clearGfxObjectsFromScene();

    if (qml_startscreen->isLoading())
    {
        QObject::connect(qml_startscreen, SIGNAL(statusChanged(QDeclarativeComponent::Status)),
                         this, SLOT(continueLoading()));
    }
    else continueLoading();
}

void Game::continueLoading()
{
    if (qml_startscreen->isError())
    {
        qWarning() << qml_startscreen->errors();
    }
    else
    {
        qmlStartScreenItem = qobject_cast<QDeclarativeItem *>(qml_startscreen->create());
        main_scene->addItem(qmlStartScreenItem);
        qmlStartScreenItem->grabKeyboard();
    }
}

void Game::clearGfxObjectsFromScene()
{
    // Let's keep the startupscreen existing
    if (main_scene->items().contains(qmlStartScreenItem))
        main_scene->removeItem(qmlStartScreenItem);
    main_scene->clear(); // Everything else can go.
}

void Game::create_level()
{
    delete current_level;
    current_level = LevelFactory::create(level, main_scene, snoopy_message, sound_handler, global_timer, this);
    setupScene();
}
