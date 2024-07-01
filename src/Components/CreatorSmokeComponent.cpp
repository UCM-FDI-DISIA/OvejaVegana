#include "CreatorSmokeComponent.h"
#include "SmokeComponent.h"

VeryReal::Component* OvejaVegana::CreatorSmokeComponent::CreatorSpecificComponent() {
    return new OvejaVegana::SmokeComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorSmokeComponent::SpecificInitComponent(VeryReal::Component* c) {
    return static_cast<OvejaVegana::SmokeComponent*>(c)->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorSmokeComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return static_cast<OvejaVegana::SmokeComponent*>(c)->InitComponent();
}
