#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "Manager.h"
#include "InputManager.h"
#include "CameraComponent.h"
#include "AudioLeon.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"

using namespace std;

bool OvejaVegana::PlayerInputComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_movement_component = this->GetEntity()->GetComponent<OvejaVegana::MovementComponent>();
	my_camera_component = this->GetEntity()->GetComponent<VeryReal::CameraComponent>();
	my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();

	if (this->my_transform != nullptr && this->my_movement_component != nullptr && this->my_camera_component != nullptr)
		return true;
	else
		return false;
}

void OvejaVegana::PlayerInputComponent::Update(const double& dt) {
	std::cout << "entro\n";
	if (!VeryReal::InputManager::Instance()->IsGameControllerConnected()) { // Movimiento Teclado
		float sprint = 0.5;
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LSHIFT)) {
			sprint = 1;
		}

		VeryReal::Vector3 forwardDirection = VeryReal::Vector3(0, 1, 0).Normalize();
		VeryReal::Vector3 rightDirection = forwardDirection.Cross(VeryReal::Vector3(0, 0, 1)).Normalize();


		float moveX = 0.0f;
		float moveY = 0.0f;
		float moveZ = 0.0f;



		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_W)) {
			moveY += forwardDirection.GetY();  // Asegúrate de que GetY realmente refleje la dirección hacia adelante
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_S)) {
			moveY -= forwardDirection.GetY();  // Asegúrate de que GetY realmente refleje la dirección hacia atrás
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_A)) {
			moveX -= rightDirection.GetX();  // Movimiento lateral izquierdo
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_D)) {
			moveX += rightDirection.GetX();  // Movimiento lateral derecho
		}

		//cout << my_transform->GetRotation().GetX() << " " << my_transform->GetRotation().GetY() << " " << my_transform->GetRotation().GetZ() << endl;
		cout << forwardDirection.GetX() << " " << forwardDirection.GetY() << " " << forwardDirection.GetZ() << endl;
		cout << rightDirection.GetX() << " " << rightDirection.GetY() << " " << rightDirection.GetZ() << endl;

		my_movement_component->SetMoventDirectionX(moveX * sprint);
		my_movement_component->SetMoventDirectionY(moveY * sprint);
		my_movement_component->SetMoventDirectionZ(moveZ * sprint);

		//Camara con teclado y raton 
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LEFT)) { // Rotar la cámara hacia la izquierda
			my_camera_component->yaw(1);
			my_rigidbody->Rotate(VeryReal::Vector3(0, 1, 0), -1);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_RIGHT)) { // Rotar la cámara hacia la derecha
			my_camera_component->yaw(-1);
			my_rigidbody->Rotate(VeryReal::Vector3(0, 1, 0), 1);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_UP)) { // Rotar la cámara hacia arriba
			my_camera_component->rotate(1, rightDirection);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_DOWN)) { // Rotar la cámara hacia abajo
			my_camera_component->rotate(-1, rightDirection);
		}


		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_ESCAPE)) {
			//VeryReal::InputManager::Instance()->Quit();
		}
	}
	else {
		float sprint = 2;
		// Movimiento Mando
		my_movement_component->SetMoventDirectionX(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX));
		my_movement_component->SetMoventDirectionZ(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY));

		// Camara Mando
		if (VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX) != 0) {
			my_camera_component->yaw(-VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX));
		}
		if (VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY) != 0) {
			my_camera_component->pitch(-VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY));
		}
	}



	// AUDIO
	audio_intensity = VeryReal::AudioLeon::Instance()->InputSoundIntensity();
}
