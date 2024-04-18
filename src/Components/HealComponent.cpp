#include "HealComponent.h"
#include "LifeComponent.h" 


using namespace OvejaVegana;

HealComponent::HealComponent() : healAmount(0) {}

HealComponent::~HealComponent() {}

bool HealComponent::InitComponent(int healAmount) {
    this->healAmount = healAmount;
    return true;
}

void HealComponent::OnCollisionEnter(VeryReal::Entity* other) {
    // Asumimos que 'other' puede tener un componente de vida
    auto lifeComp = other->GetComponent<LifeComponent>();
    if (lifeComp) {
        lifeComp->addlife(healAmount);  // Incrementa la vida del componente de vida encontrado
    }
}
