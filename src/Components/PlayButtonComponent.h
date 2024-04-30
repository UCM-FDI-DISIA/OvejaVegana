#pragma once
#ifndef PLAYBUTTONCOMPONENT
#define PLAYBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

#pragma warning(disable : 4251)

namespace OvejaVegana {
	class OVEJAVEGANA_API PlayButtonComponent : public VeryReal::UIButtonComponent {
	public:
		virtual void accion();
	};
}

#pragma warning(default : 4251)

#endif