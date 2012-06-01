#include "soundhandler.h"

#include <QApplication>
#include <phonon/mediaobject.h>

SoundHandler::SoundHandler(QObject *parent) :
    QObject(parent)
{
    sound = new Phonon::MediaObject(this);
    audioOutput =
        new Phonon::AudioOutput(Phonon::GameCategory, this);
    Phonon::createPath(sound, audioOutput);
    audioOutput->setVolume(0.15);
}

SoundHandler::~SoundHandler()
{
    delete sound;
    delete audioOutput;
}

void SoundHandler::playSound(QString filename)
{
    sound->setCurrentSource(Phonon::MediaSource(QApplication::applicationDirPath() + filename));
    sound->play();
}
