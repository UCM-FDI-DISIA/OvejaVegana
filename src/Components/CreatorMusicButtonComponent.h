#pragma once
#include <CreatorComponent.h>
#include "../Export.h"

namespace OvejaVegana {
    class OVEJAVEGANA_API CreatorMusicButtonComponent : public VeryReal::CreatorComponent {
    public:
        CreatorMusicButtonComponent() {}
        virtual ~CreatorMusicButtonComponent() {}
        VeryReal::Component* CreatorSpecificComponent() override;
        void SpecificInitComponent(VeryReal::Component* c) override;
    };
}
