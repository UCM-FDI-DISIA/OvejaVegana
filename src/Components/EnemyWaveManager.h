#pragma once
#include <Component.h>
#include "Vector2.h"

namespace VeryReal {
	class TransformComponent;
}

namespace OvejaVegana {
	class EnemyWaveComponent :public VeryReal::Component {
	private:
		int nEnemies = 0;
		float time_until_next_wave = 0;

		int nGenerateEnemies = 3;
		float safe_generation_distance = 35;
		VeryReal::Vector2 scene_topleft_corner;
		float scene_side_lenght = 1;

		int WAVES_PER_LEVEL = 3;
		int nWaves = WAVES_PER_LEVEL;

		int N_LEVELS = 2;
		int currLevel = 1;

		int nIncreaseGenerationEnemies = 1;
		float TIME_BETWEEN_WAVES = 2;

		VeryReal::TransformComponent* player_transform = nullptr;

	public:
		EnemyWaveComponent();
		virtual ~EnemyWaveComponent();
		std::pair<bool, std::string> InitComponent(int level = 1, int enemiesInitialNumber = 3);
		void Update(const double& dt);
		void GenerateNextWave();
		void EnemyDefeated() { nEnemies-=1; }
		bool IsWaveCompleated() { return nEnemies <= 0; }
		VeryReal::Vector2 GetRandomPositionAwayFromPlayer();
	};
}