#include "EnemyChaseComponent.h"
#include "Entity.h"
#include "TransformComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "Vector3.h"
#include "SceneManager.h"
#include "Scene.h"

std::pair<bool, std::string> OvejaVegana::EnemyChaseComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (this->my_transform == nullptr) {
		return { false, "Transform isn't in this entity, ERROR from EnemyChaseComponent" };
	}
	my_movement_component = this->GetEntity()->GetComponent<OvejaVegana::MovementComponent>();
	if (this->my_movement_component == nullptr) {
		return { false, "MovementComponent isn't in this entity, ERROR from EnemyChaseComponent" };
	}
	VeryReal::Scene* currScene = VeryReal::SceneManager::Instance()->GetActiveScene();

	if (currScene == nullptr) return { false, "CurrentScene = nullptr, Error from EnemyChaseComponent" };
		
	VeryReal::Entity* player = currScene->GetEntity("Player");
	if (player == nullptr)return { false, "Player doesn't exists. Error from EnemyChaseComponent" };
	
	player_transform = player->GetComponent<VeryReal::TransformComponent>();
	if (this->player_transform == nullptr) {
		return { false, "Transform isn't in player entity, ERROR from EnemyChaseComponent" };
	}
	
	/*sonidoMuerte = currScene->GetEntity("sonidoMuerte");


	
	
	 if (this->sonidoMuerte == nullptr) {
		return { false, "sonidoMuerte isn't in scene, ERROR from EnemyChaseComponent" };
	}*/
	 
		return { true, "EnemyChaseComponent created correctly" };
	
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


	// Comprobar si se destruye


}

VeryReal::Entity* OvejaVegana::EnemyChaseComponent::GetSonidoMuerte()
{
	return sonidoMuerte;
}