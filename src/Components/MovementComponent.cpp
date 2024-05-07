#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "Vector3.h"
#include "RigidBodyComponent.h"
using namespace std;

std::pair<bool, std::string> OvejaVegana::MovementComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (this->my_transform == nullptr) {
		return { false, "Transform isn't in this entity, ERROR from MovementComponent" };
	}
	else if (this->my_rigidbody == nullptr) {
		return { false, "RigidBodyComponent isn't in this entity, ERROR from MovementComponent" };
	}
	else {
		return { true, "MovementComponent created correctly" };
	}
		
}

void OvejaVegana::MovementComponent::Update(const double& dt) {
	if (IsMoving()) {
		my_rigidbody->SetPosition(my_rigidbody->GetPosition() + movementDirection * (float)(speed * dt));
	}
}

bool OvejaVegana::MovementComponent::IsMoving() {
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}