#pragma once
#include "CreatorComponent.h"
#include "../Export.h"

namespace OvejaVegana {
	class OVEJAVEGANA_API CreatorEnemyChaseComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorEnemyChaseComponent() {}
		virtual ~CreatorEnemyChaseComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
};
