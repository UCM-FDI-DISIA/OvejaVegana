#pragma once
#ifndef HEALCOMPONENT
#define HEALCOMPONENT

#include <Component.h>
#include "Entity.h"
#include "../Export.h"

namespace OvejaVegana {
    class LifeComponent;
    class OVEJAVEGANA_API HealComponent : public VeryReal::Component {
    public:
        HealComponent();
        virtual ~HealComponent();
        virtual std::pair<bool, std::string> InitComponent(int amount);
        void OnCollisionEnter(VeryReal::Entity* other) override;
        void OnCollisionExit(VeryReal::Entity* other) override;

        int getAmount() { return amount; };

    protected:
        int amount;
        bool pickedUp;
        LifeComponent* life_comp = nullptr;
    };
}

#endif