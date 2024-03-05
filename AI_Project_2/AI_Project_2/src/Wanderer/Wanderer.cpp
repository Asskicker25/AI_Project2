#include "Wanderer.h"
#include <Graphics/Renderer.h>
#include <Graphics/Panels/ImguiDrawUtils.h>

#include "States/IdleState.h"
#include "States/MoveToTargetState.h"
#include "States/FindNextTargetState.h"

Wanderer::Wanderer()
{
	name = "Wanderer";
	
	LoadModel("Assets/Models/RaceDriver.fbx");
	shader = Renderer::GetInstance().skeletalAnimShader;
	meshes[0]->material->AsMaterial()->diffuseTexture = new Texture("Assets/Textures/RaceDriver.png");

	transform.SetScale(glm::vec3(0.02f));

	AddState(eWandererState::IDLE, new IdleState());
	AddState(eWandererState::MOVE_TO_TARGET, new MoveToTargetState());
	AddState(eWandererState::FIND_NEXT_TARGET, new FindNextTargetState());
}

void Wanderer::AddState(eWandererState type, BaseState* state)
{
	mListOfStates[type] = state;
	state->mWanderer = this;
}

void Wanderer::RemoveState(eWandererState state)
{
	mListOfStates.erase(state);
}

void Wanderer::ChangeState(eWandererState state)
{
	GetCurrentState()->Cleanup();

	mCurrentState = state;
	mCurrentStateInt = (int)mCurrentState;

	GetCurrentState()->Start();
}

BaseState* Wanderer::GetCurrentState()
{
	return GetState(mCurrentState);
}

BaseState* Wanderer::GetState(eWandererState state)
{
	return mListOfStates[state];
}

void Wanderer::Start()
{
	SkeletonModel::Start();
	GetCurrentState()->Start();
}

void Wanderer::Update(float deltaTime)
{
	SkeletonModel::Update(deltaTime);
	GetCurrentState()->Update(deltaTime);
}

void Wanderer::OnPropertyDraw()
{
	SkeletonModel::OnPropertyDraw();

	if (!ImGui::TreeNodeEx("Wanderer", ImGuiTreeNodeFlags_DefaultOpen))
	{
		return;
	}

	if (ImGuiUtils::DrawDropDown("State", mCurrentStateInt, mStateStrings, 3))
	{
		ChangeState((eWandererState)mCurrentStateInt);
	}

	ImGui::TreePop();
}
