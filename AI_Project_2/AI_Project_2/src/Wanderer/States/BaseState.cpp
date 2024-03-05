#include "BaseState.h"
#include "../Wanderer.h"

void BaseState::ChangeState(eWandererState state)
{
	mWanderer->ChangeState(state);
}
