#include "CreatorMusicButtonComponent.h"
#include "MusicButtonComponent.h"

VeryReal::Component* OvejaVegana::CreatorMusicButtonComponent::CreatorSpecificComponent()
{
    return new MusicButtonComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorMusicButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::MusicButtonComponent* musicbutton_comp = static_cast<OvejaVegana::MusicButtonComponent*>(c);

    return musicbutton_comp->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorMusicButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "Nothing copied, need to be filled to be used by prefabs (CreatorMusicButtonComponent)" };
}
