#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "spoonystate.h"

class RunningState : public SpoonyState
{
    Q_OBJECT

public:
    RunningState( SpoonySprite* spoony);

private slots:

    void nextFrame();

private:
    int _counter;

};

#endif // RUNNINGSTATE_H
