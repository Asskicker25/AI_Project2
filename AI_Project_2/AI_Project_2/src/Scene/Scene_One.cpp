#include "Scene_One.h"
#include "../AppSettings.h"
#include "../AI_Application.h"


Scene_One::Scene_One(AI_Application* application)
{
	this->mApplication = application;
}

void Scene_One::Start()
{
	mMainCamera = new GameCamera();
	mMainCamera->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 500.0f, 65.0f);
	mMainCamera->transform.SetPosition(glm::vec3(0.0f, 10.0f, 30.0f));
	mMainCamera->transform.SetRotation(glm::vec3(-10, 0, 0));
	//mMainCamera->applyPostProcessing = true;

	mDirLight = new Light();
	mDirLight->transform.SetScale(glm::vec3(0.1f));
	mDirLight->transform.SetPosition(glm::vec3(0, 0, 3));
	mDirLight->transform.SetRotation(glm::vec3(10, 40, 0));
	mDirLight->InitializeLight(Directional);
	mDirLight->intensity = 0.7;

	Model* floor = new Model("res/Models/DefaultQuad.fbx");
	floor->transform.SetPosition(glm::vec3(0));
	floor->transform.SetRotation(glm::vec3(90,0,0));
	floor->transform.SetScale(glm::vec3(50));

}

void Scene_One::Update()
{

}

void Scene_One::Render()
{
}

void Scene_One::ShutDown()
{
	
}
