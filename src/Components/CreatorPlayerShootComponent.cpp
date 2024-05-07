#include "CreatorPlayerShootComponent.h"
#include "PlayerShootComponent.h"

VeryReal::Component* OvejaVegana::CreatorPlayerShootComponent::CreatorSpecificComponent() {

    return new PlayerShootComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayerShootComponent::SpecificInitComponent(VeryReal::Component* c) {
    PlayerShootComponent* psc = static_cast<OvejaVegana::PlayerShootComponent*>(c);
    return psc->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayerShootComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "Nothing copied, need to be filled to be used by prefabs (CreatorPlayerShootComponent)" };
}
