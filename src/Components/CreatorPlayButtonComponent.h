#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace OvejaVegana {
	class OVEJAVEGANA_API CreatorPlayButtonComponent : public VeryReal::CreatorComponent {
	public:
		CreatorPlayButtonComponent() {}
		virtual ~CreatorPlayButtonComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
}