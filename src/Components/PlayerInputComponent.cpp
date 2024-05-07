#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"
#include "Entity.h"

using namespace std;

std::pair<bool, std::string> OvejaVegana::PlayerInputComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_movement_component = this->GetEntity()->GetComponent<OvejaVegana::MovementComponent>();;
	my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();

	if (this->my_transform == nullptr) {
		return { false, "Transform isn't in this entity, ERROR from PlayerInputComponent" };
	}
	else if (this->my_movement_component == nullptr) {
		return { false, "MovementComponent isn't in this entity, ERROR from PlayerInputComponent" };
	}
	else if (this->my_rigidbody == nullptr) {
		return { false, "RigidBodyComponent isn't in this entity, ERROR from PlayerInputComponent" };
	}
	else
		return { true, "PlayerInputComponent created correctly" };
}

void OvejaVegana::PlayerInputComponent::Update(const double& dt) {
	if (!VeryReal::InputManager::Instance()->IsGameControllerConnected()) { // Movimiento Teclado
		float sprint = 0.5;
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LSHIFT)) {
			sprint = 1;
		}

		VeryReal::Vector3 forwardDirection = VeryReal::Vector3(0, 1, 0).Normalize();
		VeryReal::Vector3 rightDirection = forwardDirection.Cross(VeryReal::Vector3(0, 0, 1)).Normalize();

		float moveX = 0.0f;
		float moveY = 0.0f;

		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_W)) {
			moveX += forwardDirection.GetX(); moveY += forwardDirection.GetY();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_S)) {
			moveX -= forwardDirection.GetX(); moveY -= forwardDirection.GetY();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_A)) {
			moveX -= rightDirection.GetX(); moveY -= rightDirection.GetY();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_D)) {
			moveX += rightDirection.GetX(); moveY += rightDirection.GetY();
		}

		// cout << moveX << " " << moveZ << endl;

		// cout << my_rigidbody->GetPosition().GetX() << " " << my_rigidbody->GetPosition().GetY() << " " << my_rigidbody->GetPosition().GetZ() << endl;

		// cout << my_transform->GetPosition().GetX() << " " << my_transform->GetPosition().GetY() << " " <<  my_transform->GetPosition().GetZ() << endl;

		my_movement_component->SetMoventDirectionX(moveX * sprint);
		my_movement_component->SetMoventDirectionY(moveY * sprint);

		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_ESCAPE)) {
			//VeryReal::InputManager::Instance()->Quit();
		}
	}
	else { // Movimiento Mando
		float sprint = 1;
		my_movement_component->SetMoventDirectionX(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX));
		my_movement_component->SetMoventDirectionZ(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY));
	}
}
