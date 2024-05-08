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
		return { false, "UIProgressBarComponent isn't in this entity, ERROR from LifeComponent" };
	}
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
	if (my_progress_bar)my_progress_bar->setProgress(currentlife);
	if (currentlife < 1) {
		OvejaVegana::GameManager::Instance()->Lose();
		return false; 
	}
	else {
		return true;
	}
}
void OvejaVegana::LifeComponent::OnCollisionEnter(VeryReal::Entity* other) {

	if (other->GetComponent<OvejaVegana::EnemyChaseComponent>()) {
		other->GetComponent<VeryReal::ColliderComponent>()->SetActive(false);
		//life_comp->decreaselife(1.0);
	}

}