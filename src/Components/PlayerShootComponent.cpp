#include "PlayerShootComponent.h"
#include <CameraComponent.h>
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TransformComponent.h"
#include "Entity.h"

OvejaVegana::PlayerShootComponent::PlayerShootComponent() {

}

std::pair<bool, std::string> OvejaVegana::PlayerShootComponent::InitComponent() {
    my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
    if (this->my_transform == nullptr) {
        return { false, "Transform isn't in this entity, ERROR from PlayerShootComponent" };
    }
    else return { true, "PlayerShootComponent created correctly" };
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

    // Configura la posición inicial y la velocidad de la bala
    VeryReal::TransformComponent* bala_transform = bala->GetComponent<VeryReal::TransformComponent>();
    VeryReal::RigidBodyComponent* bala_rigidbody = bala->GetComponent<VeryReal::RigidBodyComponent>();
    if (bala_rigidbody != nullptr) {
        // Calcula la rotación basada en la dirección de disparo
        float angle = std::atan2(shootDirection.GetY(), shootDirection.GetX()); // Ángulo en radianes
        angle = angle * (180.0 / 3.141592); // Convertir a grados
        //bala_transform->SetRotation({ angle, 0, 0, 1 });
        //bala_transform->Rotate(VeryReal::Vector3(angle,0, 0));


        bala_transform->SetPosition(my_transform->GetPosition());
        VeryReal::Vector3 bulletVelocity = shootDirection * 100.0f; // Ajusta la velocidad de la bala según sea necesario
        //bala_transform->SetVelocity(bulletVelocity);


        // Si el componente RigidBody está presente, configura también su posición y velocidad
        bala_rigidbody->SetPosition(my_transform->GetPosition());
        bala_rigidbody->SetVelocityLinear(bulletVelocity);
    }
}
