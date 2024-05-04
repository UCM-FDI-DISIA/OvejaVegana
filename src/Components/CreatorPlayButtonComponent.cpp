#include "CreatorPlayButtonComponent.h"
#include "PlayButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorPlayButtonComponent::CreatorSpecificComponent()
{
    return new PlayButtonComponent();
}

void OvejaVegana::CreatorPlayButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::PlayButtonComponent* playbutton_comp = static_cast<OvejaVegana::PlayButtonComponent*>(c);

    if (!playbutton_comp->InitComponent()) {

    }
}

void OvejaVegana::CreatorPlayButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}