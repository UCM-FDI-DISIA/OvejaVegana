#include "HealComponent.h"
#include "LifeComponent.h" 

OvejaVegana::HealComponent::HealComponent() {}

OvejaVegana::HealComponent::~HealComponent() {}

bool OvejaVegana::HealComponent::InitComponent(int amount) {
    this->amount = amount;
    life_comp = this->GetEntity()->GetComponent<OvejaVegana::LifeComponent>();
    if (this->life_comp != nullptr)
        return false;
    return true;
}

void OvejaVegana::HealComponent::OnCollisionEnter(VeryReal::Entity* other) {
    // Asumimos que 'other' puede tener un componente de vida
    auto life_comp = other->GetComponent<OvejaVegana::LifeComponent>();
    if (life_comp) {
        life_comp->addlife(amount);  // Incrementa la vida del componente de vida encontrado
    }
}
