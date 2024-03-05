#pragma once

#include <Graphics/Scene/BaseScene.h>
#include <Graphics/Camera/GameCamera.h>
#include <Graphics/Light/Light.h>

#include "../Camera/CameraController.h"
#include "../Wanderer/Wanderer.h"


using namespace Scene;

class AI_Application;

class Scene_One : public BaseScene
{
public:

	Scene_One(AI_Application* application);

	// Inherited via BaseScene
	void Start() override;
	void Update() override;
	void Render() override;

	void ShutDown();

private:

	CameraController* mCameraController = nullptr;
	AI_Application* mApplication = nullptr;
	GameCamera* mMainCamera = nullptr;
	Light* mDirLight = nullptr;

};

