#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "snoopystate.h"

class RunningState : public SnoopyState
{
    Q_OBJECT

public:
    RunningState( SnoopySprite* snoopy);

    void onEntry ( QEvent * event );
    void onExit ( QEvent * event );

private slots:

    void nextFrame();

private:
    int _counter;

};

#endif // RUNNINGSTATE_H
