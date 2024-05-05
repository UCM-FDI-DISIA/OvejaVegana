#include "CreatorEnemyChaseComponent.h"
#include "EnemyChaseComponent.h"

VeryReal::Component* OvejaVegana::CreatorEnemyChaseComponent::CreatorSpecificComponent() {
	return new EnemyChaseComponent();
}

void OvejaVegana::CreatorEnemyChaseComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::EnemyChaseComponent* chase = static_cast<OvejaVegana::EnemyChaseComponent*>(c);

    if (!chase->InitComponent()) {
        // Gestion de error
    }
}

void OvejaVegana::CreatorEnemyChaseComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    OvejaVegana::EnemyChaseComponent* chase = static_cast<OvejaVegana::EnemyChaseComponent*>(c);

    if (!chase->InitComponent()) {
        // Gestion de error
    }
}