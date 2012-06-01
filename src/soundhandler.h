#ifndef SOUNDHANDLER_H
#define SOUNDHANDLER_H

#include <QObject>
#include <phonon/mediaobject.h>
#include <Phonon/AudioOutput>


class SoundHandler : public QObject
{
    Q_OBJECT
public:
    SoundHandler(QObject *parent = 0);
    ~SoundHandler();
    virtual void playSound(QString filename);

signals:

public slots:

private:
    Phonon::MediaObject *sound;
    Phonon::AudioOutput *audioOutput;
};

#endif // SOUNDHANDLER_H
