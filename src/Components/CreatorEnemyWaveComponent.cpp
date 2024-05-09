#include "CreatorEnemyWaveComponent.h"
#include "EnemyWaveManager.h"
VeryReal::Component* OvejaVegana::CreatorEnemyWaveComponent::CreatorSpecificComponent() {
    return new EnemyWaveManager();
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyWaveComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::EnemyWaveManager* enemywave = static_cast<OvejaVegana::EnemyWaveManager*>(c);

    return enemywave->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyWaveComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return{ true,"" };
}