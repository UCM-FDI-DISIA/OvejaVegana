#include "CreatorMovementComponent.h"
#include "MovementComponent.h"

VeryReal::Component* OvejaVegana::CreatorMovementComponent::CreatorSpecificComponent() {
    return new OvejaVegana::MovementComponent();
}

void OvejaVegana::CreatorMovementComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::MovementComponent* mc = static_cast<OvejaVegana::MovementComponent*>(c);

    if (!mc->InitComponent()) {
        // Gestion de error
    }
}
