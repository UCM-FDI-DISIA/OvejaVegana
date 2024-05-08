#include "EnemyWaveManager.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "Scene.h"
#include "Entity.h"
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace VeryReal;

bool OvejaVegana::EnemyWaveManager::InitManager() {
	Entity* player = SceneManager::Instance()->GetActiveScene()->GetEntity("Player");
	if (player != nullptr) {
		player_transform = player->GetComponent<TransformComponent>();
		if (player_transform != nullptr) {
			srand(static_cast<unsigned int>(time(nullptr))); // Semilla de numeros aleatorios
			time_until_next_wave = TIME_BETWEEN_WAVES;
			scene_topleft_corner = Vector2(-120, 215);
			scene_side_lenght = 215 - 65;
			return true;
		}
	}
	return false;
}

void OvejaVegana::EnemyWaveManager::Update(const double& dt) {
	//cout << "TIEMPO: " << time_until_next_wave << " " << "ENEMIGOS RESTANTES: " << nEnemies << endl;
	//cout << nWaves << " " << WAVES_PER_LEVEL << " " << currLevel << " " << N_LEVELS << endl;
	//cout << time_until_next_wave << endl;
	if (IsWaveCompleated()) {
		if ((time_until_next_wave -= dt) <= 0 && nWaves > 0) {
			GenerateNextWave();
			nWaves--;
			if (nWaves == 0) {
				nWaves = WAVES_PER_LEVEL;
				if (currLevel < N_LEVELS) {
					currLevel++;
					OvejaVegana::GameManager::Instance()->NextLevel();
					GenerateNextWave();
				}
				else {
					OvejaVegana::GameManager::Instance()->Win();
				}
			}
		}
	}
}

void OvejaVegana::EnemyWaveManager::GenerateNextWave() {
	for (int e = 0; e < nGenerateEnemies; ++e) {
		// Instanciar prefab
		std::string enemyID = "Enemy" + to_string('-') + "RemainingWaves_" + to_string(nWaves) + "-ID_" + to_string(e + 1);
		VeryReal::Entity* newEnemy = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabEnemy", enemyID);

		// Logica de posicionamiento alejado del jugador
		Vector2 rpos = GetRandomPositionAwayFromPlayer();
		newEnemy->GetComponent<VeryReal::RigidBodyComponent>()->SetPosition(Vector3(rpos.GetX(), rpos.GetY(), player_transform->GetPosition().GetZ()));
	}
	nEnemies = nGenerateEnemies;
	nGenerateEnemies += nIncreaseGenerationEnemies;
	time_until_next_wave = TIME_BETWEEN_WAVES;
}

VeryReal::Vector2 OvejaVegana::EnemyWaveManager::GetRandomPositionAwayFromPlayer() {
	VeryReal::Vector2 playerPosition = VeryReal::Vector2(player_transform->GetPosition().GetX(), player_transform->GetPosition().GetY());
	VeryReal::Vector2 randomPosition;
	do {
		randomPosition.SetX(scene_topleft_corner.GetX() + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * scene_side_lenght);
		randomPosition.SetY(scene_topleft_corner.GetY() - static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * scene_side_lenght);
	} while ((randomPosition - playerPosition).Magnitude() < safe_generation_distance);

	return randomPosition;
}