#include "CreatorPlayerShootComponent.h"
#include "PlayerShootComponent.h"

VeryReal::Component* OvejaVegana::CreatorPlayerShootComponent::CreatorSpecificComponent() {

    return new PlayerShootComponent();
}

void OvejaVegana::CreatorPlayerShootComponent::SpecificInitComponent(VeryReal::Component* c) {
    PlayerShootComponent* psc = static_cast<OvejaVegana::PlayerShootComponent*>(c);
    if (psc && !psc->InitComponent()) {
        // Gestionar el error si la inicialización falla
        std::cerr << "Failed to initialize PlayerShootComponent." << std::endl;
    }
}

