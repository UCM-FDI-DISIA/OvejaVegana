#include "EnemyChaseComponent.h"
#include "Entity.h"
#include "TransformComponent.h"
#include "MovementComponent.h"
#include "Vector3.h"

#include "SceneManager.h"
#include "Scene.h"

bool OvejaVegana::EnemyChaseComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_movement_component = this->GetEntity()->GetComponent<OvejaVegana::MovementComponent>();

	VeryReal::Scene* currScene = VeryReal::SceneManager::Instance()->GetScene("Level1Scene"); // Nombre de escena o currentScene

	if (currScene != nullptr) 
		player_transform = currScene->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>(); // Nombre Player

	if (this->my_movement_component != nullptr && this->my_transform != nullptr && this->player_transform != nullptr)
		return true;
	else
		return false;
}

void OvejaVegana::EnemyChaseComponent::Update(const double& dt) {
	// Calcular la direccion
    VeryReal::Vector3 playerPosition = player_transform->GetPosition();
    VeryReal::Vector3 enemyPosition = my_transform->GetPosition();

    VeryReal::Vector3 dir = (playerPosition - enemyPosition).Normalize();

    // Establecer la velocidad y direccion en el MovementComponent
    if (playerPosition.Distance(enemyPosition) <= proximity_radius)
        my_movement_component->SetSpeed(speed * slowdown_factor);
    else
        my_movement_component->SetSpeed(speed);
    my_movement_component->SetMoventDirection(dir);
}