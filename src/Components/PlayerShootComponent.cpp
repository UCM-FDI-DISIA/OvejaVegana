#include "PlayerShootComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "AudioSourceComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"

OvejaVegana::PlayerShootComponent::PlayerShootComponent() {

}

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

void OvejaVegana::PlayerShootComponent::Update(const double& dt) {
}

void OvejaVegana::PlayerShootComponent::Shoot(VeryReal::Vector3 shootDirection){
    // Crea un prefab de la bala
    VeryReal::Entity* bala = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabBala", "bala" + std::to_string(numB));
    if (!bala) {
        std::cout << "Failed to create bullet\n";
        return;
    }

    // Configura la posici�n inicial y la velocidad de la bala
    VeryReal::TransformComponent* bala_transform = bala->GetComponent<VeryReal::TransformComponent>();
    VeryReal::RigidBodyComponent* bala_rigidbody = bala->GetComponent<VeryReal::RigidBodyComponent>();
    if (bala_rigidbody != nullptr && bala_transform != nullptr) {
        // Calcula la rotaci�n basada en la direcci�n de disparo
        float angle = std::atan2(shootDirection.GetY(), shootDirection.GetX()); // �ngulo en radianes
        angle = angle * (180.0 / 3.141592); // Convertir a grados

        bala_transform->SetPosition(my_transform->GetPosition());
        VeryReal::Vector3 bulletVelocity = shootDirection * 100.0f; // Ajusta la velocidad de la bala seg�n sea necesario

        // Si el componente RigidBody est� presente, configura tambi�n su posici�n y velocidad
        bala_rigidbody->SetPosition(my_transform->GetPosition());
        bala_rigidbody->SetVelocityLinear(bulletVelocity);
    }
    my_audio->Play();
    numB++;
}
