#pragma once
#include "CreatorComponent.h"
#include "../Export.h"

namespace OvejaVegana {
	class OVEJAVEGANA_API CreatorBulletComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorBulletComponent() {}
		virtual ~CreatorBulletComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
};
