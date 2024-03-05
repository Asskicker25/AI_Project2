#pragma once
#include <iostream>
#include <Graphics/InputManager/InputManager.h>

#include "eWandererState.h"

class Wanderer;

class BaseState
{
public:
	virtual ~BaseState() {};

	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Cleanup() = 0;

	void ChangeState(eWandererState state);

	Wanderer* mWanderer = nullptr;

};

