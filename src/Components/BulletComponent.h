#pragma once
#ifndef BULLETCOMPONENT
#define BULLETCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "../Export.h"

namespace VeryReal {
	class ColliderComponent;
	class Vector3;
	class Entity;
}

namespace OvejaVegana {
	class MovementComponent;
}

namespace OvejaVegana
{
	class OVEJAVEGANA_API BulletComponent : public VeryReal::Component {
	public:
		virtual std::pair<bool, std::string> InitComponent();
		virtual void Update(const double& dt);
		void OnCollisionEnter(VeryReal::Entity* other) override;
	private:
		float damage = 1;
		float timeToLive = 5;
		VeryReal::ColliderComponent* my_collider = nullptr;
	};
}
#endif
