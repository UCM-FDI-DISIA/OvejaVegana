#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "Manager.h"
#include "InputManager.h"
#include "CameraComponent.h"
#include "TransformComponent.h"
#include "AudioLeon.h"

bool OvejaVegana::PlayerInputComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_movement_component = this->GetEntity()->GetComponent<OvejaVegana::MovementComponent>();
	my_camera_component = this->GetEntity()->GetComponent<VeryReal::CameraComponent>();

	if (this->my_movement_component != nullptr && this->my_camera_component != nullptr && my_transform != nullptr)
		return true;
	else
		return false;
}

void OvejaVegana::PlayerInputComponent::Update(const double& dt){
	if (!VeryReal::InputManager::Instance()->IsGameControllerConnected()) { // Movimiento Teclado
		float sprint = 0.5;
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LSHIFT)) {
			sprint = 1;
		}

		VeryReal::Vector3 forwardDirection = my_transform->getFacingDirection();
		VeryReal::Vector3 rightDirection = forwardDirection.Cross(VeryReal::Vector3(0, 1, 0)).Normalize();

		float moveX = 0.0f;
		float moveZ = 0.0f;

		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_W)) {
			moveX += forwardDirection.GetX();
			moveZ += forwardDirection.GetZ();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_S)) {
			moveX -= forwardDirection.GetX();
			moveZ -= forwardDirection.GetZ();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_A)) {
			moveX -= rightDirection.GetX();
			moveZ -= rightDirection.GetZ();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_D)) {
			moveX += rightDirection.GetX();
			moveZ += rightDirection.GetZ();
		}

		my_movement_component->SetMoventDirectionX(moveX * sprint);
		my_movement_component->SetMoventDirectionZ(moveZ * sprint);
		
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_ESCAPE)) {
			//VeryReal::InputManager::Instance()->Quit();
		}
	}
	else {
		float sprint = 2;
		// Movimiento Mando
		my_movement_component->SetMoventDirectionX(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX));
		my_movement_component->SetMoventDirectionZ(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY));
	}

	// AUDIO
	audio_intensity = VeryReal::AudioLeon::Instance()->InputSoundIntensity();
}

void OvejaVegana::PlayerInputComponent::setCanPickUp(bool newValue) {
	canPickUp = newValue;
}
