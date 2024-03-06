#include "IdleState.h"
#include <Graphics/MathUtils.h>

#include "../Wanderer.h"

using namespace MathUtilities;

IdleState::IdleState()
{
	//InputManager::GetInstance().AddListener(this);
}

void IdleState::Start()
{
	SetWaitTime();
	mWanderer->PlayAnimation("Idle");
}

void IdleState::Update(float deltaTime)
{
	mCurrentTime += deltaTime;

	if (mCurrentTime > mWaitTime)
	{
		mCurrentTime = 0;
		ChangeState(eWandererState::MOVE_TO_TARGET);
	}
}

void IdleState::Render()
{
}


void IdleState::Cleanup()
{
}

void IdleState::SetWaitTime()
{
	mWaitTime = MathUtils::GetRandomFloatNumber(mWanderer->mWandererInfo.mWaitTimeRange.x, mWanderer->mWandererInfo.mWaitTimeRange.y);
}

