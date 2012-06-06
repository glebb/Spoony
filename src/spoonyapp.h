#ifndef SPOONYAPP_H
#define SPOONYAPP_H

#include <QApplication>

#include <QSound>
#include "game.h"
#include "globals.h"
#include "inputintercepter.h"

class SpoonyApplication : public QApplication
{
    Q_OBJECT
public:
    SpoonyApplication(int argc, char* argv[]);
    ~SpoonyApplication();

    Game *getGame() {return game;}
signals:
    void applicationReady();

private:
    InputIntercepter *input_intercepter;
    Game *game;
    Phonon::MediaObject *music;
    Phonon::AudioOutput *audioOutput;


};

#endif // SPOONYAPP_H
