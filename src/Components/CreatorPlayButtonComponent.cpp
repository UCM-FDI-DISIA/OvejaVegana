#include "CreatorPlayButtonComponent.h"
#include "PlayButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorPlayButtonComponent::CreatorSpecificComponent()
{
    return new PlayButtonComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::PlayButtonComponent* playbutton_comp = static_cast<OvejaVegana::PlayButtonComponent*>(c);

    if (!playbutton_comp->InitComponent()) {

    }
}

std::pair<bool, std::string> OvejaVegana::CreatorPlayButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}