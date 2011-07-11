#include "snoopyapp.h"

#include <phonon/mediaobject.h>

SnoopyApp::SnoopyApp(int argc, char *argv[]):
    QApplication(argc, argv)
{
    setApplicationName("Poonsy");
    input_intercepter = new InputIntercepter();
    installEventFilter(input_intercepter);

    //Music
    Phonon::MediaObject *music =
         Phonon::createPlayer(Phonon::MusicCategory,
                              Phonon::MediaSource(QApplication::applicationDirPath() + "/sounds/entertainer.mp3"));
    music->play();

    game = new Game;
    game->initializeGame();
    game->showStartupScreen();
    connect(game, SIGNAL(ready()), this, SIGNAL(applicationReady()));
}

SnoopyApp::~SnoopyApp()
{
    delete input_intercepter;
    delete game;
//    delete music;
}
