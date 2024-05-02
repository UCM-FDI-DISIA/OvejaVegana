#pragma once
#include <Manager.h>

namespace VeryReal {
	class TransformComponent;
}

namespace OvejaVegana {
	class EnemyWaveManager :public VeryReal::Manager<EnemyWaveManager> {
	private:
		int nEnemies = 0;
		int nGenerateEnemies = 5;
		int nIncreaseGenerationEnemies = 1;
		int nWaves = 3;
		float time_until_next_wave = 0;
		float TIME_BETWEEN_WAVES = 5;

		float safe_generation_distance = 10;
		VeryReal::TransformComponent* player_transform;

	public:
		void Update(const double& dt);
		void GenerateNextWave();
		void EnemyDefeated() { nEnemies--; }
		bool IsWaveCompleated() { return nEnemies <= 0; }
	};
}