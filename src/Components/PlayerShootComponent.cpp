#include "PlayerShootComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "AudioSourceComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"
#include "SmokeEffect.h"
#include <iostream> // Para los logs

OvejaVegana::PlayerShootComponent::PlayerShootComponent() { }

std::pair<bool, std::string> OvejaVegana::PlayerShootComponent::InitComponent() {
    my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
    if (this->my_transform == nullptr) {
        return { false, "Transform isn't in this entity, ERROR from PlayerShootComponent" };
    }

    my_audio = this->GetEntity()->GetComponent<VeryReal::AudioSourceComponent>();
    if (this->my_audio == nullptr) {
        return { false, "AudioSourceComponent isn't in this entity, ERROR from PlayerShootComponent" };
    }
    my_smoke = this->GetEntity()->GetComponent<VeryReal::SmokeEffect>();
    if (this->my_smoke == nullptr) {
        return { false, "SmokeEffect isn't in this entity, ERROR from PlayerShootComponent" };
    }
    return { true, "PlayerShootComponent created correctly" };
}

void OvejaVegana::PlayerShootComponent::Update(const double& dt) {
}

void OvejaVegana::PlayerShootComponent::Shoot(VeryReal::Vector3 shootDirection) {
    // Crea un prefab de la bala
    VeryReal::Entity* bala = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabBala", "bala" + std::to_string(numB));
    if (!bala) {
        std::cout << "Failed to create bullet\n";
        return;
    }

    // Configura la posición inicial y la velocidad de la bala
    VeryReal::TransformComponent* bala_transform = bala->GetComponent<VeryReal::TransformComponent>();
    VeryReal::RigidBodyComponent* bala_rigidbody = bala->GetComponent<VeryReal::RigidBodyComponent>();
    if (bala_rigidbody != nullptr && bala_transform != nullptr) {
        // Calcula la rotación basada en la dirección de disparo
        float angle = std::atan2(shootDirection.GetY(), shootDirection.GetX()); // Ángulo en radianes
        angle = angle * (180.0 / 3.141592); // Convertir a grados

        bala_transform->SetPosition(my_transform->GetPosition());
        VeryReal::Vector3 bulletVelocity = shootDirection * 100.0f; // Ajusta la velocidad de la bala según sea necesario

        // Si el componente RigidBody está presente, configura también su posición y velocidad
        bala_rigidbody->SetPosition(my_transform->GetPosition());
        bala_rigidbody->SetVelocityLinear(bulletVelocity);
    }
    my_audio->Play();
    numB++;

    // Crear el efecto de humo
    CreateSmokeEffect(bala_transform->GetPosition(), numB);
}

void OvejaVegana::PlayerShootComponent::CreateSmokeEffect(const VeryReal::Vector3& position, int numB) {
    std::cout << "Creating SmokeEffect at Position: " << position.GetX() << ", " << position.GetY() << ", " << position.GetZ() << std::endl;
    VeryReal::Entity* smoke = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabSmoke", "smoke" + std::to_string(numB));
    if (!smoke) {
        std::cout << "Failed to create smoke\n";
        return;
    }

    VeryReal::TransformComponent* smoke_transform = smoke->GetComponent<VeryReal::TransformComponent>();
    if (smoke_transform) {
        smoke_transform->SetPosition(position);
    }
}
