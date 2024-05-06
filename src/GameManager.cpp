#include "GameManager.h"
#include "Scene.h"
#include <iostream>
#include "ScriptManager.h"
#include "EnemyWaveManager.h"
#include "SceneManager.h"
using namespace OvejaVegana;

GameManager::~GameManager() {

}

void GameManager::Start() {
	OvejaVegana::EnemyWaveManager::Init();
	VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true);
}

void GameManager::Update(const double& dt) {
	VeryReal::SceneManager::Instance()->Update(dt);

	std::string currentScene = VeryReal::SceneManager::Instance()->GetActiveScene()->GetName();
	if (currentScene == "Level1Scene" || currentScene == "Level2Scene") {
		OvejaVegana::EnemyWaveManager::Instance()->Update(dt);
	}
}

void GameManager::Menu() {
	VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true);
	VeryReal::ScriptManager::Instance()->ReadPrefabs();
}

void GameManager::Play() {
	VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("MenuScene", true);
	VeryReal::ScriptManager::Instance()->ReadScene("Level1Scene", true);
	VeryReal::ScriptManager::Instance()->ReadPrefabs();
	OvejaVegana::EnemyWaveManager::Instance()->InitManager();
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
	VeryReal::ScriptManager::Instance()->ReadScene("WinScene", true);
	VeryReal::ScriptManager::Instance()->ReadPrefabs();
}
void GameManager::NextLevel() {
	level++;
	VeryReal::SceneManager::Instance()->ActivationScene("Level1Scene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("Level1Scene", true);
	VeryReal::ScriptManager::Instance()->ReadScene("Level2Scene", true);
	VeryReal::ScriptManager::Instance()->ReadPrefabs();
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
	VeryReal::ScriptManager::Instance()->ReadScene("LoseScene", true);
	VeryReal::ScriptManager::Instance()->ReadPrefabs();
}

void GameManager::CreateRandomTrees() {
	std::cout << "I create all the trees\n";
}

int GameManager::GetLevel() {
	return level;
}