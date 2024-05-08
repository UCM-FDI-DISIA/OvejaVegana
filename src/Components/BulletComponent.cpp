#include "BulletComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "LifeComponent.h"
#include "ColliderComponent.h"
#include <EnemyChaseComponent.h>
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
	other->GetComponent<VeryReal::ColliderComponent>()->SetActive(false);
	auto enemy = other->GetComponent<OvejaVegana::EnemyChaseComponent>();


	other->GetComponent<VeryReal::ColliderComponent>()->SetActive(false);
	this->GetEntity()->SetActive(false);
}


//void OvejaVegana::BulletComponent::Update(const double& dt)