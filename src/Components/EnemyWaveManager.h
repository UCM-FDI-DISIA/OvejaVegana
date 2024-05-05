#pragma once
#include <Manager.h>
#include "Vector2.h"

namespace VeryReal {
	class TransformComponent;
}

namespace OvejaVegana {
	class EnemyWaveManager :public VeryReal::Manager<EnemyWaveManager> {
	private:
		int nEnemies = 0;
		float time_until_next_wave = 0;

		int nGenerateEnemies = 5;
		float safe_generation_distance = 30;
		VeryReal::Vector2 scene_topleft_corner;
		float scene_side_lenght = 1;

		int nWaves = 3;
		int nIncreaseGenerationEnemies = 1;
		float TIME_BETWEEN_WAVES = 2;

		VeryReal::TransformComponent* player_transform = nullptr;

	public:
		static bool Init() {
			EnemyWaveManager* a = new EnemyWaveManager();
			if (a != nullptr) {
				instance_pointer.reset(a);
				return true;
			}
			return false;
		}
		bool InitManager();
		void Update(const double& dt);
		void GenerateNextWave();
		void EnemyDefeated() { nEnemies--; }
		bool IsWaveCompleated() { return nEnemies <= 0; }
		VeryReal::Vector2 GetRandomPositionAwayFromPlayer();
	};
}