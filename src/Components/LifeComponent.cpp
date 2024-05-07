#include "LifeComponent.h"
#include "EnemyChaseComponent.h"
#include <UI/UIProgressBarComponent.h>
#include "ColliderComponent.h"
#include "Entity.h"
#include "GameManager.h"


OvejaVegana::LifeComponent::LifeComponent() {
}

OvejaVegana::LifeComponent::~LifeComponent() {

}

std::pair<bool, std::string> OvejaVegana::LifeComponent::InitComponent(float max, float ini) {
	currentlife = ini;
	maxlife = max;
	my_progress_bar = this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>();
	if (!my_progress_bar) {
		return false;
	}
	return true;
}

void OvejaVegana::LifeComponent::addlife(float toadd) {
	std::cout << "vida max: " << std::to_string(maxlife) << std::endl;
	std::cout << "vida antes: " << std::to_string(currentlife) << std::endl;
	currentlife += toadd;
	if (currentlife > maxlife) currentlife = maxlife;
	std::cout << "vida despues: " << std::to_string(currentlife) << std::endl;

	if (progressbar) {
		this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setProgress(currentlife);
	}
}
bool OvejaVegana::LifeComponent::decreaselife(float todescrease) {
	currentlife -= todescrease;
	if (progressbar)this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setProgress(currentlife);
	if (currentlife < 1) {
		OvejaVegana::GameManager::Instance()->Lose();
		return false; 
	}
	else {
		return true;
	}
}
void OvejaVegana::LifeComponent::OnCollisionEnter(VeryReal::Entity* other) {
	// Asumimos que 'other' puede tener un componente de vida
	auto life_comp = this->GetEntity()->GetComponent<OvejaVegana::LifeComponent>();
	auto enemy = other->GetComponent<OvejaVegana::EnemyChaseComponent>();

	if (life_comp) {
		//std::cout << "colision con enemigo " << std::to_string(currentlife) << std::endl;
		//enemy->destroy();
		other->GetComponent<VeryReal::ColliderComponent>()->SetActive(false);
		//life_comp->decreaselife(1.0);
		//this->GetEntity()->SetActive(false);
	}

}