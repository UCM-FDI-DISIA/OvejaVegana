#include "BulletComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "LifeComponent.h"
#include "ColliderComponent.h"
bool OvejaVegana::BulletComponent::InitComponent()
{
	my_collider = this->GetEntity()->GetComponent<VeryReal::ColliderComponent>();
	if (my_collider == nullptr) 
	{
		return false;
	}
	return true;
}

void OvejaVegana::BulletComponent::OnCollisionEnter(VeryReal::Entity* other)
{
	if(other->HasComponent("LifeComponent"))
	{
		auto lifeComponent = other->GetComponent<OvejaVegana::LifeComponent>();
		lifeComponent->decreaselife(damage);
		this->GetEntity()->SetActive(false);
	}
}