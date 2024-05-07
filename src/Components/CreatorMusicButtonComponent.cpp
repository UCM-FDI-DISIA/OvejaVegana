#include "CreatorMusicButtonComponent.h"
#include "MusicButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorMusicButtonComponent::CreatorSpecificComponent()
{
    return new MusicButtonComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorMusicButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::MusicButtonComponent* musicbutton_comp = static_cast<OvejaVegana::MusicButtonComponent*>(c);

    if (!musicbutton_comp->InitComponent()) {
        // Manejar la inicializaci�n fallida aqu�
    }
}

std::pair<bool, std::string> OvejaVegana::CreatorMusicButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
