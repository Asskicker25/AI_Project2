#include "FindNextTargetState.h"
#include "../Wanderer.h"

FindNextTargetState::FindNextTargetState()
{

}

void FindNextTargetState::Start()
{
	if (mIdleState == nullptr)
	{
		mIdleState = (IdleState*)mWanderer->GetState(eWandererState::IDLE);
	}

	ChangeState(eWandererState::IDLE);
}

void FindNextTargetState::Update(float deltaTime)
{
}

void FindNextTargetState::Cleanup()
{
}
