#ifndef SNOOPYAPP_H
#define SNOOPYAPP_H

#include <QApplication>

#include <QSound>
#include "game.h"
#include "globals.h"
#include "inputintercepter.h"

class SnoopyApplication : public QApplication
{
    Q_OBJECT
public:
    SnoopyApplication(int argc, char* argv[]);
    ~SnoopyApplication();

    Game *getGame() {return game;}
signals:
    void applicationReady();

private:
    InputIntercepter *input_intercepter;
    Game *game;
    QSound *music;

};

#endif // SNOOPYAPP_H
