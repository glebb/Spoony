#ifndef STANDINGSTATE_H
#define STANDINGSTATE_H

#include "snoopystate.h"

class SnoopySprite;

class StandingState : public SnoopyState
{
public:
    StandingState(SnoopySprite* snoopy);
};

#endif // STANDINGSTATE_H
