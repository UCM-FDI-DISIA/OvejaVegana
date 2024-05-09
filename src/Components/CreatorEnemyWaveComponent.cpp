#include "CreatorEnemyWaveComponent.h"
#include "EnemyWaveManager.h"
VeryReal::Component* OvejaVegana::CreatorEnemyWaveComponent::CreatorSpecificComponent() {
    return new EnemyWaveComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyWaveComponent::SpecificInitComponent(VeryReal::Component* c) {
    OvejaVegana::EnemyWaveComponent* enemywave = static_cast<OvejaVegana::EnemyWaveComponent*>(c);
    
    int level;
    if (parameters_map.find("level") != parameters_map.end()) {
        if (std::holds_alternative<int>(parameters_map.at("level").GetVariant())) {
            level = std::get<int>(parameters_map.at("level").GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para level este sera seteado por defecto" << std::endl;
            level = 1;
        }
    }
    else {
        std::cout << "No existe ningun parametro level este sera seteado por defecto" << std::endl;
        level = 1;
    }

    int startingEnemies;
    if (parameters_map.find("startingEnemies") != parameters_map.end()) {
        if (std::holds_alternative<int>(parameters_map.at("startingEnemies").GetVariant())) {
            startingEnemies = std::get<int>(parameters_map.at("startingEnemies").GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para startingEnemies este sera seteado por defecto" << std::endl;
            startingEnemies = 3;
        }
    }
    else {
        std::cout << "No existe ningun parametro startingEnemies este sera seteado por defecto" << std::endl;
        startingEnemies = 3;
    }

    return enemywave->InitComponent(level, startingEnemies);
}

std::pair<bool, std::string> OvejaVegana::CreatorEnemyWaveComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return{ true,"" };
}