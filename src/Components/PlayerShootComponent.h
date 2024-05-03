#pragma once

#ifndef PLAYER_SHOOT_COMPONENT_H
#define PLAYER_SHOOT_COMPONENT_H

#include "Component.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "../Export.h"


namespace VeryReal {
    class TransformComponent;
    class RigidBodyComponent;
    class CameraComponent;
    class ScriptManager;
}

namespace OvejaVegana {
    class MovementComponent;

}

#pragma warning(disable : 4251)

namespace OvejaVegana {

    class OVEJAVEGANA_API PlayerShootComponent : public VeryReal::Component {
    private:
        VeryReal::TransformComponent* my_transform = nullptr;
        VeryReal::TransformComponent* bala_transform = nullptr;
        OvejaVegana::MovementComponent* my_movement_component = nullptr;
        VeryReal::RigidBodyComponent* my_rigidbody = nullptr;

        VeryReal::CameraComponent* my_camera_component = nullptr;
        float shootRate;  // Velocidad de disparo en balas por segundo
        double timeSinceLastShot;
        int numB = 0;
    public:
        PlayerShootComponent();
        virtual bool InitComponent();
        virtual void Update(const double& dt);
        void Shoot();
        VeryReal::Vector3 GetMouseDirection();
    };

}

#pragma warning(default : 4251)

#endif // PLAYER_SHOOT_COMPONENT_H
