#include "MoveToTargetState.h"

#include <Graphics/Renderer.h>
#include <Graphics/MathUtils.h>

#include "../Wanderer.h"

using namespace MathUtilities;


MoveToTargetState::MoveToTargetState()
{
}

void MoveToTargetState::Start()
{
	mWanderer->PlayAnimation("Walk");

	CalculateMoveDir();
}

void MoveToTargetState::Update(float deltaTime)
{
	HandleTargetReached();
	HandleMove(deltaTime);
	HandleRotation(deltaTime);
}

void MoveToTargetState::Render()
{
	Renderer::GetInstance().DrawSphere(mTargetPosition, 0.2f, glm::vec4(0, 1, 0, 1));
}

void MoveToTargetState::Cleanup()
{
}

void MoveToTargetState::SetTargetPosition(glm::vec3 targetPosition)
{
	mTargetPosition = targetPosition;
}

void MoveToTargetState::CalculateMoveDir()
{
	mMoveDir = glm::normalize(mTargetPosition - mWanderer->transform.position);

	mLookAtQuat = glm::quatLookAt(-mMoveDir, glm::vec3(0, 1, 0));
}

void MoveToTargetState::HandleMove(float deltaTime)
{
	mWanderer->transform.position += mMoveDir * deltaTime * mWanderer->mWandererInfo.mSpeed;
}

void MoveToTargetState::HandleRotation(float deltaTime)
{
	glm::quat currentDirQuat = glm::slerp(mWanderer->transform.quaternionRotation, mLookAtQuat, deltaTime * mRotateSpeed);
	mWanderer->transform.SetQuatRotation(currentDirQuat);
}

void MoveToTargetState::HandleTargetReached()
{
	glm::vec3 diff = mTargetPosition - mWanderer->transform.position;

	float sqDist = glm::dot(diff, diff);

	if (sqDist < mTargetReachedRadius * mTargetReachedRadius)
	{
		ChangeState(eWandererState::FIND_NEXT_TARGET);
	}
}


