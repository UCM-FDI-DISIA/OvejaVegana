#include "CreatorPlayerInputComponent.h"
#include "PlayerInputComponent.h"

VeryReal::Component* OvejaVegana::CreatorPlayerInputComponent::CreatorSpecificComponent() {
    return new PlayerInputComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayerInputComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::PlayerInputComponent* pi = static_cast<OvejaVegana::PlayerInputComponent*>(c);

    return pi->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayerInputComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "Nothing copied, need to be filled to be used by prefabs (CreatorPlayerInputComponent)" };
}