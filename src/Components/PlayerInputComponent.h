#pragma once
#ifndef INPUTCOMPONENT
#define INPUTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"

namespace VeryReal {
	class TransformComponent;
	class CameraComponent;
}

namespace OvejaVegana {
	class MovementComponent;
}

#pragma warning(disable : 4251)

namespace OvejaVegana {
	class OVEJAVEGANA_API PlayerInputComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		void setCanPickUp(bool newValue);

	private:
		double sensitivity = 0.1;
		std::pair<int32_t, int32_t> prev_mouse_pos;

		float audio_intensity = 0;
		bool canPickUp = false;

		VeryReal::TransformComponent* my_transform = nullptr;
		OvejaVegana::MovementComponent* my_movement_component = nullptr;
		VeryReal::CameraComponent* my_camera_component = nullptr;
	};
}

#pragma warning(default : 4251)

#endif