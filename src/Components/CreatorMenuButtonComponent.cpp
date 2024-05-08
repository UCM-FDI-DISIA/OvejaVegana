#include "CreatorMenuButtonComponent.h"
#include "MenuButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorMenuButtonComponent::CreatorSpecificComponent()
{
    return new MenuButtonComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorMenuButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::MenuButtonComponent* menubutton_comp = static_cast<OvejaVegana::MenuButtonComponent*>(c);
    return menubutton_comp->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorMenuButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, " " };
}