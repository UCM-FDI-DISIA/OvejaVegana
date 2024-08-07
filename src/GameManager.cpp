#include "GameManager.h"
#include "Scene.h"
#include <iostream>
#include "ScriptManager.h"
#include "EnemyWaveManager.h"
#include "SceneManager.h"
#include "ErrorManager.h"
using namespace OvejaVegana;

GameManager::~GameManager() {

}

std::pair<bool, std::string> GameManager::Start() {
	return VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true);

}


void GameManager::Menu() {
	std::string currentScene = VeryReal::SceneManager::Instance()->GetActiveScene()->GetName();
	if (currentScene == "WinScene") {
		VeryReal::SceneManager::Instance()->ActivationScene("WinScene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("WinScene", true);
	}
	else if (currentScene == "LoseScene") {
		VeryReal::SceneManager::Instance()->ActivationScene("LoseScene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("LoseScene", true);
	}
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true));
}

void GameManager::Play() {
	VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("MenuScene", true);
	level = 0;
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("Level1Scene", true));
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadPrefabs());
}

void GameManager::Win() {
	if (level == 0) {
		VeryReal::SceneManager::Instance()->ActivationScene("Level1Scene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("Level1Scene", true);
	}
	else if (level == 1) {
		VeryReal::SceneManager::Instance()->ActivationScene("Level2Scene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("Level2Scene", true);
	}
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("WinScene", true));
	
}

void GameManager::NextLevel() {
	level++;
	VeryReal::SceneManager::Instance()->ActivationScene("Level1Scene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("Level1Scene", true);
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("Level2Scene", true));
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadPrefabs());
}

void GameManager::Lose() {
	if (level == 0) {
		VeryReal::SceneManager::Instance()->ActivationScene("Level1Scene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("Level1Scene", true);
	}
	else if (level == 1) {
		VeryReal::SceneManager::Instance()->ActivationScene("Level2Scene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("Level2Scene", true);
	}
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("LoseScene", true));
}

void GameManager::CreateRandomTrees() {
	std::cout << "I create all the trees\n";
}

int GameManager::GetLevel() {
	return level;
}