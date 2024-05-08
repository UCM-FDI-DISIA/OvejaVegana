#pragma once
#ifndef INPUTCOMPONENT
#define INPUTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"

namespace VeryReal {
	class TransformComponent;
	class RigidBodyComponent;
}

namespace OvejaVegana {
	class MovementComponent;
	class PlayerShootComponent;

}

#pragma warning(disable : 4251)

namespace OvejaVegana {
	class OVEJAVEGANA_API PlayerInputComponent : public VeryReal::Component {
	public:
		virtual std::pair<bool, std::string> InitComponent();
		virtual void Update(const double& dt);

	private:
		VeryReal::TransformComponent* my_transform = nullptr;
		OvejaVegana::MovementComponent* my_movement_component = nullptr;
		OvejaVegana::PlayerShootComponent* my_shoot_component = nullptr;
		VeryReal::RigidBodyComponent* my_rigidbody = nullptr;

		float shootRate = 1.0f;  // Velocidad de disparo en balas por segundo
		double timeSinceLastShot;
		int numB = 0;
	};
}

#pragma warning(default : 4251)

#endif