#include "CreatorEnemyChaseComponent.h"
#include "EnemyChaseComponent.h"

VeryReal::Component* OvejaVegana::CreatorEnemyChaseComponent::CreatorSpecificComponent() {
	return new EnemyChaseComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyChaseComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::EnemyChaseComponent* chase = static_cast<OvejaVegana::EnemyChaseComponent*>(c);

    if (!chase->InitComponent()) {
        // Gestion de error
    }
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyChaseComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    OvejaVegana::EnemyChaseComponent* chase = static_cast<OvejaVegana::EnemyChaseComponent*>(c);

    if (!chase->InitComponent()) {
        // Gestion de error
    }
}