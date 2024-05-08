#pragma once
#ifndef MENUBUTTONCOMPONENT
#define MENUBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace OvejaVegana {
	class OVEJAVEGANA_API MenuButtonComponent : public VeryReal::UIButtonComponent {
	public:
		virtual void Action();
	};
}
#endif