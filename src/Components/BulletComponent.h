#pragma once
#ifndef BULLETCOMPONENT
#define BULLETCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"
namespace VeryReal {
	class ColliderComponent;
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
		virtual void Update(const double& dt) {}
		virtual void OnCollisionEnter(VeryReal::Entity* other);
	private:
		float damage = 1;
		VeryReal::ColliderComponent* my_collider = nullptr;
	};
}
#endif
