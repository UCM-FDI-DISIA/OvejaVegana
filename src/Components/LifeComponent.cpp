#include "LifeComponent.h"
#include <UI/UIProgressBarComponent.h>
#include <Entity.h>

using namespace OvejaVegana;

LifeComponent::LifeComponent() {
	currentlife = 1;
	maxlife = 10;
	progressbar = false;
}

LifeComponent::~LifeComponent() {

}

bool LifeComponent::InitComponent(float max, float initial) {
	currentlife = initial;
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

void LifeComponent::addlife(float toadd) {
	currentlife += toadd;
	if (currentlife > maxlife) currentlife = maxlife;
	if (progressbar) {
		this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setProgress(currentlife);
	}
}
bool LifeComponent::decreaselife(float todescrease) {
	currentlife -= todescrease;
	if (progressbar)this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>()->setProgress(currentlife);
	if (currentlife < 1) {
		return false; 
	}
	else {
		return true;
	}
}