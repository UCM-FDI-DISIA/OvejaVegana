#include "LifeComponent.h"
#include <UI/UIProgressBarComponent.h>
#include <Entity.h>

OvejaVegana::LifeComponent::LifeComponent() {
}

OvejaVegana::LifeComponent::~LifeComponent() {

}

bool OvejaVegana::LifeComponent::InitComponent(float max) {
	currentlife = max;
	maxlife = max;
	if (this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>() == nullptr) {
		progressbar = false;
	}
	else {
		progressbar = true;
		this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setProgress(currentlife);
		this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setMaximun(max);
	}
	return true;
}

void OvejaVegana::LifeComponent::addlife(float toadd) {
	currentlife += toadd;
	if (currentlife > maxlife) currentlife = maxlife;
	if (progressbar) {
		this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setProgress(currentlife);
	}
}
bool OvejaVegana::LifeComponent::decreaselife(float todescrease) {
	currentlife -= todescrease;
	if (progressbar)this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setProgress(currentlife);
	if (currentlife < 1) {
		return false; 
	}
	else {
		return true;
	}
}