#pragma once

#include <Animation/SkeletonModel.h>
#include "States/eWandererState.h"
#include "States/BaseState.h"

class Wanderer : public SkeletonModel
{
public:

	~Wanderer() = default;
	Wanderer();

	void AddState(eWandererState type, BaseState* state);
	void RemoveState(eWandererState state);
	void ChangeState(eWandererState state);

	BaseState* GetCurrentState();
	BaseState* GetState(eWandererState state);

	virtual void Start() override;
	virtual void Update(float deltaTime) override;
	virtual void OnPropertyDraw() override;


private:
	eWandererState mCurrentState = eWandererState::FIND_NEXT_TARGET;

	int mCurrentStateInt = (int)mCurrentState;
	const char* mStateStrings[3] = { "Idle", "Move", "Find" };

	std::unordered_map<eWandererState, BaseState*> mListOfStates;
};

