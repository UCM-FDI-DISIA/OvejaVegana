#pragma once

#ifndef PLAYER_SHOOT_COMPONENT_H
#define PLAYER_SHOOT_COMPONENT_H

#include "Component.h"
#include "Entity.h"
#include "../Export.h"

namespace VeryReal {
    class TransformComponent;
    class RigidBodyComponent;
    class AudioSourceComponent;
}

#pragma warning(disable : 4251)

namespace OvejaVegana {

    class OVEJAVEGANA_API PlayerShootComponent : public VeryReal::Component {
    private:
        VeryReal::TransformComponent* my_transform = nullptr;
        VeryReal::RigidBodyComponent* my_rigidbody = nullptr;
        VeryReal::AudioSourceComponent* my_audio = nullptr;
        int numB = 0;

        void CreateSmokeEffect(const VeryReal::Vector3& position);

    public:
        PlayerShootComponent();
        virtual std::pair<bool, std::string> InitComponent();
        virtual void Update(const double& dt);
        void Shoot(VeryReal::Vector3 shootDirection);
    };

}

#pragma warning(default : 4251)

#endif // PLAYER_SHOOT_COMPONENT_H
