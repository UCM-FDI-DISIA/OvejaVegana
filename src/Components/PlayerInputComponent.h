#pragma once
#ifndef INPUTCOMPONENT
#define INPUTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"
namespace VeryReal {
	class CameraComponent;
}
namespace OvejaVegana 
{
	class MovementComponent;
}

namespace OvejaVegana
{
	class OVEJAVEGANA_API PlayerInputComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		inline bool IsFlashLightPressed() { return flashlight; }
		void setCanPickUp(bool newValue);

	private:
		double sensitivity = 0.1;
		std::pair<int32_t, int32_t> prev_mouse_pos;

		float audio_intensity;
		bool flashlight, canPickUp = false;

		OvejaVegana::MovementComponent* my_movement_component;
		VeryReal::CameraComponent* my_camera_component;
	};
}
#endif