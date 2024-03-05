#include "AI_Application.h"


void AI_Application::SetUp()
{
	viewportCamera->InitializeCamera(PERSPECTIVE, windowWidth, windowHeight, 0.1f, 500.0f, 65.0f);
	viewportCamera->transform.SetPosition(glm::vec3(0.0f, 10.0f, 30.0f));
	viewportCamera->transform.SetRotation(glm::vec3(-10, 0, 0));
	viewportCamera->applyPostProcessing = true;

	EditorLayout::GetInstance().SetMaximizeState(true);

	sceneOne = new Scene_One(this);

	SceneManager::GetInstance().AddScene("SceneOne", sceneOne);
	SceneManager::GetInstance().ChangeScene("SceneOne");
}

void AI_Application::Update()
{
}

void AI_Application::Render()
{
}

void AI_Application::Shutdown()
{
}

void AI_Application::OnPlayStateChanged(bool state)
{
}

void AI_Application::ProcessInput(GLFWwindow* window)
{
}

void AI_Application::KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods)
{
}

void AI_Application::MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods)
{
}
