#include "PlayerShootComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "AudioSourceComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"
#include <SmokeComponent.h>

OvejaVegana::PlayerShootComponent::PlayerShootComponent() {}

std::pair<bool, std::string> OvejaVegana::PlayerShootComponent::InitComponent() {
    my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
    if (this->my_transform == nullptr) {
        return { false, "Transform isn't in this entity, ERROR from PlayerShootComponent" };
    }

    my_audio = this->GetEntity()->GetComponent<VeryReal::AudioSourceComponent>();
    if (this->my_audio == nullptr) {
        return { false, "AudioSourceComponent isn't in this entity, ERROR from PlayerShootComponent" };
    }

    return { true, "PlayerShootComponent created correctly" };
}

void OvejaVegana::PlayerShootComponent::Update(const double& dt) {}

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
        bala_transform->SetPosition(my_transform->GetPosition());
        VeryReal::Vector3 bulletVelocity = shootDirection * 100.0f; // Ajusta la velocidad de la bala según sea necesario

        bala_rigidbody->SetPosition(my_transform->GetPosition());
        bala_rigidbody->SetVelocityLinear(bulletVelocity);
    }

    // Crear el efecto de humo en la dirección del disparo usando CreateSmokeEffect
    OvejaVegana::SmokeComponent* smoke_component = bala->GetComponent<OvejaVegana::SmokeComponent>();
    if (smoke_component) {
        smoke_component->CreateSmokeEffect(bala_transform->GetPosition());
    }
    else {
        std::cout << "SmokeComponent not found\n";
    }

    my_audio->Play();
    numB++;
}
