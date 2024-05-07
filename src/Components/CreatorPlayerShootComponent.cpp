#include "CreatorPlayerShootComponent.h"
#include "PlayerShootComponent.h"

VeryReal::Component* OvejaVegana::CreatorPlayerShootComponent::CreatorSpecificComponent() {

    return new PlayerShootComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayerShootComponent::SpecificInitComponent(VeryReal::Component* c) {
    PlayerShootComponent* psc = static_cast<OvejaVegana::PlayerShootComponent*>(c);
    if (psc && !psc->InitComponent()) {
        // Gestionar el error si la inicialización falla
        std::cerr << "Failed to initialize PlayerShootComponent." << std::endl;
    }
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayerShootComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
