#ifndef JUMPINGSTATE_H
#define JUMPINGSTATE_H

#include "snoopystate.h"

class SnoopySprite;

class JumpingState : public SnoopyState
{
public:
    JumpingState(SnoopySprite* snoopy);
};

#endif // JUMPINGSTATE_H
