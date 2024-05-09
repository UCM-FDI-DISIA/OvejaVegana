#include "MenuButtonComponent.h"
#include "GameManager.h"
#include "CameraComponent.h"
#include "Entity.h"
#include "Scene.h"

void OvejaVegana::MenuButtonComponent::Action()
{
	my_cam = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Camera")->GetComponent<VeryReal::CameraComponent>();
	my_cam->desactive();
	OvejaVegana::GameManager::Instance()->Menu();
}