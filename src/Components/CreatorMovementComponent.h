#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace OvejaVegana {
	class OVEJAVEGANA_API CreatorMovementComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorMovementComponent() {}
		virtual ~CreatorMovementComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}
