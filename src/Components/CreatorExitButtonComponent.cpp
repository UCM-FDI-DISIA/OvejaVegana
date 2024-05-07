#include "CreatorExitButtonComponent.h"
#include "ExitButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorExitButtonComponent::CreatorSpecificComponent()
{
    return new ExitButtonComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorExitButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::ExitButtonComponent* exitbutton_comp = static_cast<OvejaVegana::ExitButtonComponent*>(c);

    if (!exitbutton_comp->InitComponent()) {

    }
}

std::pair<bool, std::string> OvejaVegana::CreatorExitButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}