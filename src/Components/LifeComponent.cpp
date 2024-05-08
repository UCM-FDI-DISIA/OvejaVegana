#include "LifeComponent.h"
#include "EnemyChaseComponent.h"
#include "PlayerInputComponent.h"
#include <UI/UIProgressBarComponent.h>
#include "ColliderComponent.h"
#include "Entity.h"
#include "GameManager.h"
#include "EnemyWaveManager.h"
#include "LifeComponent.h"


OvejaVegana::LifeComponent::LifeComponent() {
}

OvejaVegana::LifeComponent::~LifeComponent() {

}

std::pair<bool, std::string> OvejaVegana::LifeComponent::InitComponent(float max) {
	
	if (this->GetEntity()->GetComponent<OvejaVegana::PlayerInputComponent>() != nullptr)
	{
		eType = player;
		my_progress_bar = this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>();
		if (!my_progress_bar) {
			return { false, "UIProgressBarComponent isn't in this entity, ERROR from LifeComponent" };
		}
	}
	else
		eType = enemy;

	currentlife = max;
	maxlife = max;

	return { true, "LifeComponent created correctly" };

}

void OvejaVegana::LifeComponent::addlife(float toadd) {
	std::cout << "vida max: " << std::to_string(maxlife) << std::endl;
	std::cout << "vida antes: " << std::to_string(currentlife) << std::endl;
	currentlife += toadd;
	if (currentlife > maxlife) currentlife = maxlife;
	std::cout << "vida despues: " << std::to_string(currentlife) << std::endl;

	if (my_progress_bar) {
		my_progress_bar->setProgress(currentlife);
	}
}
bool OvejaVegana::LifeComponent::decreaselife(float todescrease) {

	currentlife -= todescrease;
	if(eType == player)
		std::cout << "vida act player : " << std::to_string(currentlife) << std::endl;
	else if(eType == enemy)
		std::cout << "vida act enemigo: " << std::to_string(currentlife) << std::endl;


	if (my_progress_bar)
		my_progress_bar->setProgress(currentlife);
	if (currentlife < 1) {
		if (eType == player) OvejaVegana::GameManager::Instance()->Lose();

		else if (eType == enemy) 
		{
			//OvejaVegana::EnemyWaveManager::Instance()->EnemyDefeated();
			//this->GetEntity()->GetComponent<VeryReal::ColliderComponent>()->SetActive(false);
			//this->GetEntity()->SetActive(false);
		}
		return false; 
	}
	else {
		return true;
	}
}
void OvejaVegana::LifeComponent::OnCollisionEnter(VeryReal::Entity* other) {

	if (this->GetEntity()->GetComponent<OvejaVegana::PlayerInputComponent>() && other->GetComponent<OvejaVegana::EnemyChaseComponent>()) {
		//quita vida al enemigo
		decreaselife(1.0);
		other->GetComponent<OvejaVegana::LifeComponent>()->decreaselife(1.0);
	}

}
