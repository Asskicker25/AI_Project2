#pragma once
#include "BaseState.h"

class IdleState : public BaseState, public iInputListener
{
public:

	IdleState();

	// Inherited via BaseState
	void Start() override;
	void Update(float deltaTime) override;
	void Cleanup() override;

	glm::vec2 mWaitTimeRange = glm::vec2(1, 3);

private:

	void SetWaitTime();

	float mWaitTime = 0;
	float mCurrentTime = 0;

	glm::vec2 mInputAxis = glm::vec2(0);


};

