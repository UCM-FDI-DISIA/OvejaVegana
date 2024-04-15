#pragma once
#ifndef BULLETCOMPONENT
#define BULLETCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"
namespace VeryReal {
	class TransformComponent;
	class Vector3;
	class Entity;
}

namespace OvejaVegana
{
	class MovementComponent;
}

namespace OvejaVegana
{
	class OVEJAVEGANA_API BulletComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
		void ShootBullet(VeryReal::Vector3 dir);
		virtual void OnCollisionEnter(VeryReal::Entity* other);
	private:
		float damage = 1;
		OvejaVegana::MovementComponent* my_movement_component = nullptr;
		VeryReal::TransformComponent* my_transform = nullptr;
	};
}
#endif
