#include "CreatorExitButtonComponent.h"
#include "ExitButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorExitButtonComponent::CreatorSpecificComponent()
{
    return new ExitButtonComponent();
}

void OvejaVegana::CreatorExitButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::ExitButtonComponent* exitbutton_comp = static_cast<OvejaVegana::ExitButtonComponent*>(c);

    if (!exitbutton_comp->InitComponent()) {

    }
}