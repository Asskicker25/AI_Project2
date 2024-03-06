#pragma once
#include "BaseState.h" 
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class MoveToTargetState : public BaseState
{
public:

	MoveToTargetState();

	// Inherited via BaseState
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Cleanup() override;

	void SetTargetPosition(glm::vec3 targetPosition);

private:

	void CalculateMoveDir();
	void HandleMove(float deltaTime);
	void HandleRotation(float deltaTime);
	void HandleTargetReached();

	float mTargetReachedRadius = 0.1f;
	float mRotateSpeed = 10.0f;

	glm::vec3 mTargetPosition = glm::vec3(0);
	glm::vec3 mMoveDir = glm::vec3(0);

	glm::quat mLookAtQuat;

};

