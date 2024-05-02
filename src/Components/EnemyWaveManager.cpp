#include "EnemyWaveManager.h"

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
	}
	nGenerateEnemies += nIncreaseGenerationEnemies;
	time_until_next_wave == TIME_BETWEEN_WAVES;
}
