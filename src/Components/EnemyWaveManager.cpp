#include "EnemyWaveManager.h"
#include "TransformComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"

using namespace std;
using namespace VeryReal;

bool OvejaVegana::EnemyWaveManager::InitManager() {
	Entity* player = SceneManager::Instance()->GetActiveScene()->GetEntity("Player");
	if (player != nullptr) {
		VeryReal::TransformComponent* player_transform = player->GetComponent<TransformComponent>();
		if (player_transform != nullptr) {
			return true;
		}
	}
	return false;
}

void OvejaVegana::EnemyWaveManager::Update(const double& dt) {
	if (IsWaveCompleated()) {
		if(time_until_next_wave -= dt <= 0 && nWaves > 0){
			GenerateNextWave();
		}
	}
}

void OvejaVegana::EnemyWaveManager::GenerateNextWave() {
	for (int e = 0; e < nGenerateEnemies; ++e) {
		// Instanciar prefab
		std::string enemyID = "Enemy" + to_string(nWaves) + "-RemainingWaves_" + to_string(nWaves) + "-ID_" + to_string(e + 1);
		VeryReal::Entity* newEnemy = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabEnemy", enemyID);
		
		// Logica de posicionamiento alejado del jugador
		newEnemy->GetComponent<VeryReal::TransformComponent>()->SetPosition(player_transform->GetPosition() + VeryReal::Vector3(0, 35, 0));
	}
	nEnemies = nGenerateEnemies;
	nGenerateEnemies += nIncreaseGenerationEnemies;
	time_until_next_wave = TIME_BETWEEN_WAVES;
}
