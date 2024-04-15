#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

bool OvejaVegana::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (this->my_transform != NULL)
		return true;
	else 
		return false;
}

void OvejaVegana::MovementComponent::Update(const double& dt) {
	std::cout << dt<<std::endl;
	if (IsMoving()) {
		my_transform->Translate(movementDirection * speed * dt);
	}
}

bool OvejaVegana::MovementComponent::IsMoving()
{
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}