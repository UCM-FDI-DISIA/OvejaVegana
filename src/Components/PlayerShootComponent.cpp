#include "PlayerShootComponent.h"
#include "InputManager.h"
#include "AudioManager.h"
#include <CameraComponent.h>
#include "MovementComponent.h"
#include "RigidBodyComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ScriptManager.h"

OvejaVegana::PlayerShootComponent::PlayerShootComponent()
        :shootRate(1.0f), timeSinceLastShot(0) {

    }

    bool OvejaVegana::PlayerShootComponent::InitComponent() {
        my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
        my_movement_component = this->GetEntity()->GetComponent<OvejaVegana::MovementComponent>();
        my_camera_component = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Camera")->GetComponent<VeryReal::CameraComponent>();
        my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
        if (this->my_transform != nullptr && this->my_movement_component != nullptr && this->my_rigidbody != nullptr && this->my_camera_component != nullptr)
            return true;
        else
            return false;
    }

    void OvejaVegana::PlayerShootComponent::Update(const double& dt) {
        timeSinceLastShot += dt;
        //std::cout << " vale\n";

        if (timeSinceLastShot >= 1.0 / shootRate) {
            Shoot();
            numB++;
            timeSinceLastShot = 0;
        }
    }

    void OvejaVegana::PlayerShootComponent::Shoot() {
        if (my_transform == nullptr) return;

        // Calcula la dirección de disparo, esto podría ser hacia donde apunta el ratón o la mira del jugador
        VeryReal::Vector3 shootDirection = GetMouseDirection();
        shootDirection.SetZ(0);
        // Asume que tienes un método para reproducir sonidos en AudioManager
        //VeryReal::AudioManager::Instance().PlaySound("shoot_sound");

        // Crea un prefab de la bala desde el Scene Manager
        VeryReal::Entity* bala = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabBala", "bala"+ std::to_string(numB) );

        if (!bala) std::cout << " nop\n"; // Asegúrate de que la bala se ha creado correctamente

        // Obtén el componente transform de la bala
        bala_transform = bala->GetComponent<VeryReal::TransformComponent>();
        if (bala_transform == nullptr) return;

        // Configura la posición inicial de la bala en la posición del jugador más alguna compensación si es necesario
        bala_transform->SetPosition(my_transform->GetPosition());

        // Configura la velocidad de la bala
        float velocidadInicial = 1.0f; // Define la velocidad inicial de la bala
        VeryReal::Vector3 velocidadBala = shootDirection.Normalize() * velocidadInicial;
        bala_transform->SetVelocity(velocidadBala);

        // Si tu juego maneja físicas, quizás necesites añadir un RigidBodyComponent
        auto bala_rigidbody = bala->GetComponent<VeryReal::RigidBodyComponent>();
        bala_rigidbody->SetPosition(my_rigidbody->GetPosition());
        if (bala_rigidbody) {
            bala_rigidbody->SetVelocityLinear(velocidadBala);
        }

        std::cout << bala->GetName() + std::to_string(numB) << " " << bala_rigidbody->GetPosition().GetX() << " " << bala_rigidbody->GetPosition().GetY() << " " << bala_rigidbody->GetPosition().GetZ() << "\n";
    }

    VeryReal::Vector3 OvejaVegana::PlayerShootComponent::GetMouseDirection() {
        auto mousePosPair = VeryReal::InputManager::Instance()->GetMousePos(); // Suponiendo que devuelve std::pair<int, int>
        VeryReal::Vector2 mousePos(static_cast<float>(mousePosPair.first), static_cast<float>(mousePosPair.second)); // Convierte std::pair a Vector2

        VeryReal::Vector3 worldDirection = my_camera_component->ScreenToWorldPoint(mousePos); // Asegúrate de que my_camera_component está correctamente inicializado y es de tipo CameraComponent


        //std::cout << mousePos.GetX() << " "<< mousePos.GetY() << " mundo " << worldDirection.GetX()<<" "<<worldDirection.GetY() << " "<< worldDirection.GetZ() << " " << " entro jajaj\n";
        return worldDirection.Normalize();
    }


