#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

#include "globals.h"
#include "soundhandler.h"

class Level;
class SnoopyMessaging;
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

    int getCurrentLevelNr() { return _currentLevelNr; }
    int getRound() { return _rounds; }
    int getLives() { return _lives; }

    void setCurrentLevel(int level);
    void setCurrentLevel(Level *level);
    Level * getCurrentLevel() { return _currentLevel; }

    QTimer *timer;

    void showStartupScreen();
    Q_INVOKABLE void start(int lives=LIVES, int level=1);

public slots:
    void onDie();
    void nextLevel();
    void restartGame();
    void resetLevel();
    void continueLoading();

signals:
    void ready();

private:
    void _createLevel(int nr);
    void _clearScreen();

    Level *_currentLevel;
    QGraphicsSimpleTextItem *_text;
    int _rounds;
    int _lives;
    int _currentLevelNr;

    SnoopyMessaging *_m;

    QGraphicsScene *_scene;
    QGraphicsView *_view;

    int _speed;

    QDeclarativeEngine *_engine;
    QDeclarativeComponent *_component;
    QDeclarativeItem *_item;

    SoundHandler *_sound;





};

#endif // GAME_H
