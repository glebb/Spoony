#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

#include "globals.h"
#include "soundhandler.h"

class Level;
class SnoopyMessage;
class QDeclarativeEngine;
class QDeclarativeComponent;
class QDeclarativeItem;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    ~Game();

    void initializeGame();

    int getCurrentLevelNr() { return level; }
    int getRound() { return gamerounds_completed; }
    int getLives() { return global_lives; }

    void setCurrentLevel(int level);
    void setCurrentLevel(Level *level);
    Level * getCurrentLevel() { return current_level; }

    QTimer *global_timer;

    void showStartupScreen();
    Q_INVOKABLE void start(int lives=LIVES, int level=1);

public slots:
    void onDie();
    void playNextLevel();
    void restartGame();
    void resetLevel();
    void continueLoading();

signals:
    void ready();

private:
    void setupScene();
    void clearGfxObjectsFromScene();
    void create_level();

    Level *current_level;
    QGraphicsSimpleTextItem *lives_text;
    int gamerounds_completed;
    int global_lives;
    int level;

    SnoopyMessage *snoopy_message;

    QGraphicsScene *main_scene;
    QGraphicsView *main_view;

    int global_speed;

    QDeclarativeEngine *qml_engine;
    QDeclarativeComponent *qml_startscreen;
    QDeclarativeItem *qmlStartScreenItem;

    SoundHandler *sound_handler;





};

#endif // GAME_H
