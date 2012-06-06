#include "snoopyapp.h"

#include <phonon/mediaobject.h>

SnoopyApplication::SnoopyApplication(int argc, char *argv[]):
    QApplication(argc, argv)
{
    setApplicationName("Snoopy");
    input_intercepter = new InputIntercepter();
    installEventFilter(input_intercepter);

    //Music
    audioOutput =
        new Phonon::AudioOutput(Phonon::GameCategory, this);
    music = new Phonon::MediaObject(this);
    Phonon::createPath(music, audioOutput);
    audioOutput->setVolume(0.25);
    music->setCurrentSource(Phonon::MediaSource(QApplication::applicationDirPath()
                                                + "/sounds/entertainer.mp3"));
    music->play();
    game = new Game;
    game->initializeGame();
    game->showStartupScreen();
    connect(game, SIGNAL(ready()), this, SIGNAL(applicationReady()));
}

SnoopyApplication::~SnoopyApplication()
{
    delete input_intercepter;
    delete game;
    delete music;
    delete audioOutput;
}

