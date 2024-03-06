#pragma once
#include "BaseState.h"
#include "MoveToTargetState.h"

class FindNextTargetState : public BaseState
{

public:
	FindNextTargetState();

	// Inherited via BaseState
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Cleanup() override;

private:

	MoveToTargetState* mMoveToTargetState = nullptr;

	// Inherited via BaseState
};

