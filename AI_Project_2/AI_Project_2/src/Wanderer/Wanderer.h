#pragma once

#include <Animation/SkeletonModel.h>
#include "States/eWandererState.h"
#include "States/BaseState.h"

struct WandererInfo
{
	float mSpeed = 2;
	float mNextTargetRadius_1 = 10;
	float mAngleOfChange = 360;

	glm::vec2 mWaitTimeRange = glm::vec2(1, 3);
};

class Wanderer : public SkeletonModel
{
public:

	~Wanderer() = default;
	Wanderer(WandererInfo& wandererInfo);

	void AddState(eWandererState type, BaseState* state);
	void RemoveState(eWandererState state);
	void ChangeState(eWandererState state);

	BaseState* GetCurrentState();
	BaseState* GetState(eWandererState state);

	virtual void Start() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnPropertyDraw() override;

	WandererInfo mWandererInfo;

private:
	eWandererState mCurrentState = eWandererState::FIND_NEXT_TARGET;

	int mCurrentStateInt = (int)mCurrentState;
	const char* mStateStrings[3] = { "Idle", "Move", "Find" };

	std::unordered_map<eWandererState, BaseState*> mListOfStates;
};

