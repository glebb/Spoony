#include "soundhandler.h"

#include <QApplication>
#include <phonon/mediaobject.h>

SoundHandler::SoundHandler(QObject *parent) :
    QObject(parent)
{
    sound = Phonon::createPlayer(Phonon::MusicCategory);

}

SoundHandler::~SoundHandler()
{
    delete sound;
}

void SoundHandler::playSound(QString filename)
{
    sound->setCurrentSource(Phonon::MediaSource(QApplication::applicationDirPath() + filename));
    sound->play();
}
