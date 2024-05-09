#include "LifeComponent.h"
#include "EnemyChaseComponent.h"
#include "PlayerInputComponent.h"
#include <UI/UIProgressBarComponent.h>
#include "ColliderComponent.h"
#include "Entity.h"
#include "GameManager.h"
#include "EnemyWaveManager.h"
#include "LifeComponent.h"
#include "SceneManager.h"
#include "Scene.h"

using namespace VeryReal;
using namespace OvejaVegana;
OvejaVegana::LifeComponent::LifeComponent() {
}

OvejaVegana::LifeComponent::~LifeComponent() {

}

std::pair<bool, std::string> OvejaVegana::LifeComponent::InitComponent(float max) {
	
	if (this->GetEntity()->GetComponent<OvejaVegana::PlayerInputComponent>())
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
	currentlife += toadd;
	if (currentlife > maxlife) currentlife = maxlife;

	if (my_progress_bar) {
		my_progress_bar->setProgress(currentlife);
	}
}
bool OvejaVegana::LifeComponent::decreaselife(float todescrease) {

	currentlife -= todescrease;
	if (eType == player)
	{
		if (my_progress_bar)
			my_progress_bar->setProgress(currentlife);
	}


	if (currentlife < 1) {
		if (eType == player) 
			OvejaVegana::GameManager::Instance()->Lose();
		else if (eType == enemy) 
		{
			VeryReal::Entity* e= VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("EnemyWave");
			if (e != nullptr)
			{
				OvejaVegana::EnemyWaveComponent* ewm = e->GetComponent<EnemyWaveComponent>();
				if (ewm != nullptr) {
					ewm->EnemyDefeated();
				}
			}
			this->GetEntity()->GetComponent<VeryReal::ColliderComponent>()->SetActive(false);
			this->GetEntity()->SetActive(false);
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
		this->GetEntity()->GetComponent<OvejaVegana::LifeComponent>()->decreaselife(1.0);
		other->GetComponent<OvejaVegana::LifeComponent>()->decreaselife(1.0);
	}
}
