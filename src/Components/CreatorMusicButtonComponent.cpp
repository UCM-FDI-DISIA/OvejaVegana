#include "CreatorMusicButtonComponent.h"
#include "MusicButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorMusicButtonComponent::CreatorSpecificComponent()
{
    return new MusicButtonComponent();
}

void OvejaVegana::CreatorMusicButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::MusicButtonComponent* musicbutton_comp = static_cast<OvejaVegana::MusicButtonComponent*>(c);

    if (!musicbutton_comp->InitComponent()) {
        // Manejar la inicialización fallida aquí
    }
}
