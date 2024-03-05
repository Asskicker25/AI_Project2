#include "Wanderer.h"
#include <Graphics/Renderer.h>

Wanderer::Wanderer()
{
	name = "Wanderer";
	
	LoadModel("Assets/Models/RaceDriver.fbx");
	shader = Renderer::GetInstance().skeletalAnimShader;
	meshes[0]->material->AsMaterial()->diffuseTexture = new Texture("Assets/Textures/RaceDriver.png");

	transform.SetScale(glm::vec3(0.02f));
}
