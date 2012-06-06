#ifndef STANDINGSTATE_H
#define STANDINGSTATE_H

#include "spoonystate.h"

class SpoonySprite;

class StandingState : public SpoonyState
{
public:
    StandingState(SpoonySprite* spoony);
};

#endif // STANDINGSTATE_H
