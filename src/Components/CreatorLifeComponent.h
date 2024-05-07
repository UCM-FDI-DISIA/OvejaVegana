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
		std::pair<bool, std::string> SpecificInitComponent(VeryReal::Component* c) override;
		std::pair<bool, std::string> SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
};
