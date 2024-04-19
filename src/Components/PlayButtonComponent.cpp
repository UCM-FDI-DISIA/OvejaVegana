#include "PlayButtonComponent.h"
#include "SceneManager.h"
#include "ScriptManager.h"

bool OvejaVegana::PlayButtonComponent::InitComponent()
{
	return true;
}

void OvejaVegana::PlayButtonComponent::accion()
{
	VeryReal::SceneManager::Instance()->RemoveScene("MainMenu"); // RemoveScene
	VeryReal::SceneManager::Instance()->AddScene("Level1", true); // AddScene
	VeryReal::ScriptManager::Instance()->NewScene("Level1");
	VeryReal::ScriptManager::Instance()->ReadScene("Level1"); // ReadScene
}