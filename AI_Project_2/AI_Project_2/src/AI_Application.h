#pragma once
#include "Scene/Scene_One.h"

#include <Graphics/ApplicationWindow.h>

class AI_Application : public ApplicationWindow
{
public:

	Scene_One* sceneOne = nullptr;

	// Inherited via ApplicationWindow
	void SetUp() override;
	void Update() override;
	void Render() override;
	void Shutdown() override;
	void OnPlayStateChanged(bool state) override;
	void ProcessInput(GLFWwindow* window) override;
	void KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods) override;
	void MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods) override;
};

