#include "CreatorHealComponent.h"
#include "HealComponent.h"

VeryReal::Component* OvejaVegana::CreatorHealComponent::CreatorSpecificComponent()
{
    return new HealComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorHealComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::HealComponent* heal_comp = static_cast<OvejaVegana::HealComponent*>(c);
    int amount;

#pragma region Position

    if (parameters_map.find("amount") != parameters_map.end()) {
        if (std::holds_alternative<int>(parameters_map.at("amount")->GetVariant())) {
            amount = std::get<int>(parameters_map.at("amount")->GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para cantidad de curacion este sera seteado por defecto" << std::endl;
            amount = 1;
        }
    }
    else {
        std::cout << "No existe ningun parametro amount este sera seteado por defecto" << std::endl;
        amount = 1;
    }
#pragma endregion
    return heal_comp->InitComponent(amount);
}
std::pair<bool, std::string> OvejaVegana::CreatorHealComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {    HealComponent* t = static_cast<HealComponent*>(c);
    HealComponent* copia = static_cast<HealComponent*>(other);
    return t->InitComponent(copia->getAmount());
}
