#pragma once
#include "BaseState.h"

class IdleState : public BaseState, public iInputListener
{
public:

	IdleState();

	// Inherited via BaseState
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Cleanup() override;

private:

	void SetWaitTime();

	float mWaitTime = 0;
	float mCurrentTime = 0;

	glm::vec2 mInputAxis = glm::vec2(0);

};

