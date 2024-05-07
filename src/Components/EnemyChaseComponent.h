#pragma once
#include "Component.h"

namespace VeryReal {
	class TransformComponent;
}

namespace OvejaVegana {
	class MovementComponent;
}

namespace OvejaVegana {
	class EnemyChaseComponent : public VeryReal::Component {
	public:

		virtual std::pair<bool, std::string> InitComponent();
		virtual void Update(const double& dt);
		 void destroy();

	private:
		VeryReal::TransformComponent* player_transform = nullptr;
		VeryReal::TransformComponent* my_transform = nullptr;
		OvejaVegana::MovementComponent* my_movement_component = nullptr;
		float speed = 5.0f; // Velocidad de movimiento del enemigo
		float proximity_radius = 10.0f; // Radio de proximidad
		float slowdown_factor = 0.8f; // Disminucion de velocidad
	};
}