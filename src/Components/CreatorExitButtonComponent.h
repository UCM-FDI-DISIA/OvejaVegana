#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace OvejaVegana {
	class OVEJAVEGANA_API CreatorExitButtonComponent : public VeryReal::CreatorComponent {
	public:
		CreatorExitButtonComponent() {}
		virtual ~CreatorExitButtonComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}