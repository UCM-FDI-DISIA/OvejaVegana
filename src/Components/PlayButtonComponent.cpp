#include "PlayButtonComponent.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "ScriptManager.h"
#include "GameManager.h"

void OvejaVegana::PlayButtonComponent::Action() {
	VeryReal::AM().StopEverySound();
	OvejaVegana::GameManager::Instance()->Play();
}