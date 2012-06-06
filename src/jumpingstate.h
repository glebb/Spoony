#ifndef JUMPINGSTATE_H
#define JUMPINGSTATE_H

#include "spoonystate.h"

class SpoonySprite;

class JumpingState : public SpoonyState
{
public:
    JumpingState(SpoonySprite* spoony);
};

#endif // JUMPINGSTATE_H
