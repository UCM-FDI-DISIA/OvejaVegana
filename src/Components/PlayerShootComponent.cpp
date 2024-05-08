#include "PlayerShootComponent.h"
#include "InputManager.h"
#include "AudioManager.h"
#include <CameraComponent.h>
#include "MovementComponent.h"
#include "RigidBodyComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ScriptManager.h"
#include "RenderManager.h"
#include "Window.h"

OvejaVegana::PlayerShootComponent::PlayerShootComponent()
        :shootRate(1.0f), timeSinceLastShot(0) {

    }

std::pair<bool, std::string> OvejaVegana::PlayerShootComponent::InitComponent() {
    my_transform = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
    my_movement_component = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player")->GetComponent<OvejaVegana::MovementComponent>();
    my_camera_component = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Camera")->GetComponent<VeryReal::CameraComponent>();
    my_rigidbody = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player")->GetComponent<VeryReal::RigidBodyComponent>();
    if (this->my_transform == nullptr) {
        return { false, "Transform isn't in this entity, ERROR from PlayerShootComponent" };
    }
    else if (this->my_movement_component == nullptr){
        return { false, "MovementComponent isn't in this entity, ERROR from PlayerShootComponent" };
    }
    else if (this->my_rigidbody == nullptr) {
        return { false, "RigidBodyComponent isn't in this entity, ERROR from PlayerShootComponent" };
    }
    else if (this->my_camera_component == nullptr) {
        return { false, "CameraComponent isn't in camera entity, ERROR from PlayerShootComponent" };
    }
    else {
        return { true, "PlayerShootComponent created correctly" };
    }
}

void OvejaVegana::PlayerShootComponent::Update(const double& dt) {
}

void OvejaVegana::PlayerShootComponent::Shoot(VeryReal::Vector3 shootDirection){

    if (my_transform == nullptr) return;

    // Normaliza la dirección de disparo para asegurarte de que tiene una magnitud constante
    if (shootDirection.GetX() != 0 || shootDirection.GetY() != 0 || shootDirection.GetZ() != 0) { // Comprueba que la dirección no sea cero
        shootDirection.Normalize();
    }
    else {
        return; // No dispara si no hay dirección de disparo
    }

    // Crea un prefab de la bala
    VeryReal::Entity* bala = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabBala", "bala" + std::to_string(numB));
    if (!bala) {
        std::cout << "Failed to create bullet\n";
        return;
    }

    // Configura la posición inicial y la velocidad de la bala
    VeryReal::TransformComponent* bala_transform = bala->GetComponent<VeryReal::TransformComponent>();
    if (bala_transform) {
        bala_transform->SetPosition(my_transform->GetPosition());
        VeryReal::Vector3 bulletVelocity = shootDirection * 100.0f; // Ajusta la velocidad de la bala según sea necesario
        bala_transform->SetVelocity(bulletVelocity);

        // Si el componente RigidBody está presente, configura también su posición y velocidad
        VeryReal::RigidBodyComponent* bala_rigidbody = bala->GetComponent<VeryReal::RigidBodyComponent>();
        if (bala_rigidbody) {
            bala_rigidbody->SetPosition(my_transform->GetPosition());
            bala_rigidbody->SetVelocityLinear(bulletVelocity);
        }
    }
}
