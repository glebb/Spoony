#ifndef JUMPINGSTATE_H
#define JUMPINGSTATE_H

#include "snoopystate.h"

class SnoopySprite;

class JumpingState : public SnoopyState
{
public:
    JumpingState(SnoopySprite* snoopy);
    void onEntry ( QEvent * event );
    void onExit ( QEvent * event );

private slots:
    void nextFrame();

private:
    int _counter;

};

#endif // JUMPINGSTATE_H
