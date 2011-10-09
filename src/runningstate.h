#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "snoopystate.h"

class RunningState : public SnoopyState
{
    Q_OBJECT

public:
    RunningState( SnoopySprite* snoopy);

private slots:

    void nextFrame();

private:
    int _counter;

};

#endif // RUNNINGSTATE_H
