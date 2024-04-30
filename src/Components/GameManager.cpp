#include "GameManager.h"
#include "Scene.h"
using namespace OvejaVegana;
GameManager::~GameManager() {

}
void GameManager::Start() {
	//aquí añadiremos todas las escena del juego(Menu, Pausa, Juego,Win , Loose) y dejaremos activa la del Menu Inicial
	scene_manager->AddScene("Menu", false);
	scene_manager->AddScene("Play", false);
	scene_manager->AddScene("Pause", false);
	scene_manager->AddScene("Win", false);
	scene_manager->AddScene("Loose", false);
	
}
void GameManager::Update(const double& dt) {
	scene_manager->Update(dt);
}
void GameManager::Menu() {
	scene_manager->ActivationScene("Menu", true);
	scene_manager->ActivationScene("Play", false);
	scene_manager->ActivationScene("Pause", false);
	scene_manager->ActivationScene("Win", false);
	scene_manager->ActivationScene("Loose", false);
}
void GameManager::Pause() {
	scene_manager->ActivationScene("Pause", true);
	scene_manager->ActivationScene("Play", false);
}
void GameManager::Play() {
	scene_manager->ActivationScene("Play", true);
	scene_manager->ActivationScene("Pause", false);
	scene_manager->ActivationScene("Menu", false);
}
void GameManager::Win() {
	scene_manager->ActivationScene("Win", true);
	scene_manager->ActivationScene("Play", false);
}
void GameManager::Loose() {
	scene_manager->ActivationScene("Loose", true);
	scene_manager->ActivationScene("Play", false);
}