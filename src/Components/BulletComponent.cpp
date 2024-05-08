#include "BulletComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "LifeComponent.h"
#include "ColliderComponent.h"
std::pair<bool, std::string> OvejaVegana::BulletComponent::InitComponent()
{
	my_collider = this->GetEntity()->GetComponent<VeryReal::ColliderComponent>();
	if (my_collider == nullptr) 
	{
		return { false, "ColliderComponent isn't in this entity, ERROR from BulletComponent" };
	}
	return { true, "BulletComponent created correctly" };
}

void OvejaVegana::BulletComponent::OnCollisionEnter(VeryReal::Entity* other) {
	if(other->HasComponent("LifeComponent")) {
		auto lifeComponent = other->GetComponent<OvejaVegana::LifeComponent>();
		lifeComponent->decreaselife(damage);
		this->GetEntity()->SetActive(false);
	}
}

//void OvejaVegana::BulletComponent::Update(const double& dt)