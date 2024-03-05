#pragma once
#include "BaseState.h"
#include "IdleState.h"

class FindNextTargetState : public BaseState
{

public:
	FindNextTargetState();

	// Inherited via BaseState
	void Start() override;
	void Update(float deltaTime) override;
	void Cleanup() override;

private:

	IdleState* mIdleState = nullptr;
};

