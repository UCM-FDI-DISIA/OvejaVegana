#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace OvejaVegana {
    class OVEJAVEGANA_API CreatorPlayerShootComponent : public VeryReal::CreatorComponent {
    private:
    public:
        CreatorPlayerShootComponent() {}
        virtual ~CreatorPlayerShootComponent() {}
        VeryReal::Component* CreatorSpecificComponent() override;
        void SpecificInitComponent(VeryReal::Component* c) override;
    };
}

