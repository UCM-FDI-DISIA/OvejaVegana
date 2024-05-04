#pragma once
#include "CreatorComponent.h"
#include "../Export.h"

namespace OvejaVegana {
	class OVEJAVEGANA_API CreatorHealComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorHealComponent() {}
		virtual ~CreatorHealComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
};
