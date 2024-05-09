#include "CreatorEnemyWaveComponent.h"
#include "EnemyWaveManager.h"
VeryReal::Component* OvejaVegana::CreatorEnemyWaveComponent::CreatorSpecificComponent() {
    return new EnemyWaveComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyWaveComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::EnemyWaveComponent* enemywave = static_cast<OvejaVegana::EnemyWaveComponent*>(c);

    return enemywave->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyWaveComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return{ true,"" };
}