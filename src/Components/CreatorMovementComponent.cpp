#include "CreatorMovementComponent.h"
#include "MovementComponent.h"

VeryReal::Component* OvejaVegana::CreatorMovementComponent::CreatorSpecificComponent() {
    return new OvejaVegana::MovementComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorMovementComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::MovementComponent* mc = static_cast<OvejaVegana::MovementComponent*>(c);

    return mc->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorMovementComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    OvejaVegana::MovementComponent* mc = static_cast<OvejaVegana::MovementComponent*>(c);

    return mc->InitComponent();
}
