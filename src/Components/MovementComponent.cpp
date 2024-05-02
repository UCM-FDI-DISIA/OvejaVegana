#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "Vector3.h"
#include "RigidBodyComponent.h"
using namespace std;

bool OvejaVegana::MovementComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (this->my_transform != nullptr && this->my_rigidbody != nullptr)
		return true;
	else
		return false;
}

void OvejaVegana::MovementComponent::Update(const double& dt) {
	if (IsMoving()) {
		my_rigidbody->SetPosition(my_rigidbody->GetPosition() + movementDirection * (float)(speed * dt));
	}
	else {
		my_rigidbody->Decelerate(4);
	}
}

bool OvejaVegana::MovementComponent::IsMoving() {
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}