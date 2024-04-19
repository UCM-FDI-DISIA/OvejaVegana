#pragma once
#ifndef PLAYBUTTONCOMPONENT
#define PLAYBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace OvejaVegana {
	class OVEJAVEGANA_API PlayButtonComponent : public VeryReal::UIButtonComponent {
	public:
		virtual bool InitComponent();
		virtual void accion();
	};
}
#endif