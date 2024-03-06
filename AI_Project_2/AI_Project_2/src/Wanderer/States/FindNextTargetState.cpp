#include "FindNextTargetState.h"
#include "../Wanderer.h"

#include <Graphics/MathUtils.h>

using namespace MathUtilities;

FindNextTargetState::FindNextTargetState()
{

}

void FindNextTargetState::Start()
{
	if (mMoveToTargetState == nullptr)
	{
		mMoveToTargetState = (MoveToTargetState*)mWanderer->GetState(eWandererState::MOVE_TO_TARGET);
	}

	float randomAngle = MathUtils::GetRandomFloatNumber(0, mWanderer->mWandererInfo.mAngleOfChange);
	randomAngle = MathUtils::GetRandomIntNumber(0, 1) == 0 ? randomAngle : -randomAngle;

	glm::vec3 forward = -mWanderer->transform.GetForward();
	glm::vec3 right = -mWanderer->transform.GetRight();
	glm::vec3 rotationAxis = glm::cross(forward, right);
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(randomAngle), rotationAxis);
	glm::vec3 newDir = rotationMatrix * glm::vec4(forward, 1.0f);


	glm::vec3 nextPos = mWanderer->transform.position + newDir * mWanderer->mWandererInfo.mNextTargetRadius_1;
	mMoveToTargetState->SetTargetPosition(nextPos);


	ChangeState(eWandererState::IDLE);
}

void FindNextTargetState::Update(float deltaTime)
{
}

void FindNextTargetState::Render()
{
}

void FindNextTargetState::Cleanup()
{
}

