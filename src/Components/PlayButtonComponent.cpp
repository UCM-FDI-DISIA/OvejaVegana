#include "PlayButtonComponent.h"
#include "SceneManager.h"
#include "ScriptManager.h"
#include "GameManager.h"

void OvejaVegana::PlayButtonComponent::Action() {
	OvejaVegana::GameManager::Instance()->Play();
}