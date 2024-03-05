#pragma once
#include "BaseState.h" 

class MoveToTargetState : public BaseState
{
public:

	MoveToTargetState();

	// Inherited via BaseState
	void Start() override;
	void Update(float deltaTime) override;
	void Cleanup() override;
};

