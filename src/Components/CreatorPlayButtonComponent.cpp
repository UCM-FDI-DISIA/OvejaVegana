#include "CreatorPlayButtonComponent.h"
#include "PlayButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorPlayButtonComponent::CreatorSpecificComponent()
{
    return new PlayButtonComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::PlayButtonComponent* playbutton_comp = static_cast<OvejaVegana::PlayButtonComponent*>(c);

    return playbutton_comp->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "Nothing copied, need to be filled to be used by prefabs (CreatorPlayButtonComponent)" };
}