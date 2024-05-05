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
}
void GameManager::Pause() {

}
void GameManager::Play() {
	VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("MenuScene", true);
	VeryReal::ScriptManager::Instance()->ReadScene("Level1Scene", true);
	VeryReal::ScriptManager::Instance()->ReadPrefabs();
	OvejaVegana::EnemyWaveManager::Instance()->InitManager();
}
void GameManager::Win() {
	VeryReal::ScriptManager::Instance()->ReadScene("WinScene", true);
}
void GameManager::Lose() {
	VeryReal::ScriptManager::Instance()->ReadScene("LoseScene", true);
}

void GameManager::CreateRandomTrees() {
	std::cout << "I create all the trees\n";
}