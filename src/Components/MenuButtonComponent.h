#pragma once
#ifndef MENUBUTTONCOMPONENT
#define MENUBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace VeryReal {
	class CameraComponent;
}

namespace OvejaVegana {
	class OVEJAVEGANA_API MenuButtonComponent : public VeryReal::UIButtonComponent {
	public:
		virtual void Action();
	private:
		VeryReal::CameraComponent* my_cam = nullptr;
	};
}
#endif