#pragma once
#include "CreatorComponent.h"
#include "../Export.h"

namespace OvejaVegana {
	class OVEJAVEGANA_API CreatorLifeComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorLifeComponent() {}
		virtual ~CreatorLifeComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
};
