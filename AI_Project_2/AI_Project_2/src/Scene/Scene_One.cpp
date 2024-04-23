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

	mCameraController = new CameraController(mMainCamera);

	Model* floor = new Model("res/Models/DefaultQuad.fbx");
	floor->meshes[0]->material->AsMaterial()->diffuseTexture = new Texture("Assets/Textures/Floor.jpg");
	floor->meshes[0]->material->AsMaterial()->textureTiling = glm::vec2(15, 15);
	floor->name = "Floor";
	floor->transform.SetPosition(glm::vec3(0));
	floor->transform.SetRotation(glm::vec3(90,0,0));
	floor->transform.SetScale(glm::vec3(50));

	WandererInfo wandererInfo1;
	wandererInfo1.mSpeed = 5;
	Wanderer* wanderer1 = new Wanderer(wandererInfo1);
	wanderer1->meshes[0]->material->AsMaterial()->diffuseTexture = new Texture("Assets/Textures/Red.jpg");

	WandererInfo wandererInfo2;
	wandererInfo1.mAngleOfChange = 30;
	Wanderer* wanderer2 = new Wanderer(wandererInfo2);
	wanderer2->transform.SetPosition(glm::vec3(10, 0, 0));
	wanderer2->meshes[0]->material->AsMaterial()->diffuseTexture = new Texture("Assets/Textures/Green.jpg");
	
	WandererInfo wandererInfo3;
	wandererInfo3.mWaitTimeRange = glm::vec2(4, 6);
	Wanderer* wanderer3 = new Wanderer(wandererInfo3);
	wanderer3->transform.SetPosition(glm::vec3(-10, 0, 0));
	wanderer3->meshes[0]->material->AsMaterial()->diffuseTexture = new Texture("Assets/Textures/Blue.jpg");

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
