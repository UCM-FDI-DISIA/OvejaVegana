#pragma once
#ifndef HEALCOMPONENT
#define HEALCOMPONENT

#include <Component.h>
#include "Entity.h"
#include "../Export.h"

namespace OvejaVegana {
    class HealComponent : public VeryReal::Component {
    public:
        HealComponent();
        virtual ~HealComponent();

        bool InitComponent(float healAmount);
        void OnCollisionEnter(VeryReal::Entity* other) override;

    private:
        float healAmount; // Cantidad de vida que el componente proporcionará al jugador al colisionar.
    };

}

#endif