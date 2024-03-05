#include "IdleState.h"
#include <Graphics/MathUtils.h>

using namespace MathUtilities;

IdleState::IdleState()
{
	//InputManager::GetInstance().AddListener(this);
}

void IdleState::Start()
{
	SetWaitTime();
	//mWanderer->PlayAnimation("Idle");
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

void IdleState::Cleanup()
{
}

void IdleState::SetWaitTime()
{
	mWaitTime = MathUtils::GetRandomFloatNumber(mWaitTimeRange.x, mWaitTimeRange.y);
}

