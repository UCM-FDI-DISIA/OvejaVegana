#include "MenuButtonComponent.h"
#include "GameManager.h"
#include "CameraComponent.h"
#include "Entity.h"
#include "Scene.h"

void OvejaVegana::MenuButtonComponent::Action()
{
	
	
	OvejaVegana::GameManager::Instance()->Menu();
}