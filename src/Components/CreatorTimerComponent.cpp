#include "CreatorTimerComponent.h"
#include "TimerComponent.h"

VeryReal::Component* OvejaVegana::CreatorTimerComponent::CreatorSpecificComponent()
{
	return new TimerComponent();
}

void OvejaVegana::CreatorTimerComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::TimerComponent* pi = static_cast<OvejaVegana::TimerComponent*>(c);

    if (!pi->InitComponent()) {
        // Gestion de error
    }
}