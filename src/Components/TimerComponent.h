#pragma once
#ifndef TIMERCOMPONENT
#define TIMERCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"

namespace VeryReal {
	
}

#pragma warning(disable : 4251)

namespace OvejaVegana {
	class OVEJAVEGANA_API TimerComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

	private:
		
	};
}

#pragma warning(default : 4251)

#endif