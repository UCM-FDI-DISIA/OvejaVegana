#include "CreatorLifeComponent.h"
#include "LifeComponent.h"

VeryReal::Component* OvejaVegana::CreatorLifeComponent::CreatorSpecificComponent()
{
    return new LifeComponent();
}

void OvejaVegana::CreatorLifeComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::LifeComponent* life_comp = static_cast<OvejaVegana::LifeComponent*>(c);
    float maxlife;
    float inilife;

#pragma region Position

    if (parameters_map.find("health") != parameters_map.end()) {
        if (std::holds_alternative<int>(parameters_map.at("health")->GetVariant())) {
            maxlife = std::get<int>(parameters_map.at("health")->GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para la vida maxima este sera seteado por defecto" << std::endl;
            maxlife = 3;
        }
    }
    else {
        std::cout << "No existe ningun parametro health este sera seteado por defecto" << std::endl;
        maxlife = 3;
    }
    inilife = 1;
#pragma endregion
    bool b = life_comp->InitComponent(maxlife, inilife);
    if (!b) {
    }
}

void OvejaVegana::CreatorLifeComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    int a = 0;
    LifeComponent* t = static_cast<LifeComponent*>(c);
    LifeComponent* copia = static_cast<LifeComponent*>(other);
    bool b = t->InitComponent(copia->getMaxLife(), copia->getMaxLife());
    if (!b) {
    }
}