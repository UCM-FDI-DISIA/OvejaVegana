#include "HealComponent.h"
#include "LifeComponent.h" 

OvejaVegana::HealComponent::HealComponent() {}

OvejaVegana::HealComponent::~HealComponent() {}

std::pair<bool, std::string> OvejaVegana::HealComponent::InitComponent(int amount) {
    pickedUp = false;
    this->amount = amount;
    life_comp = this->GetEntity()->GetComponent<OvejaVegana::LifeComponent>();
    if (this->life_comp != nullptr)
        return { false, "LifeComponent isn't in this entity, ERROR from HealComponent" };
    return { true, "HealComponent created correctly" };
}


void OvejaVegana::HealComponent::OnCollisionEnter(VeryReal::Entity* other) {
    // Asumimos que 'other' puede tener un componente de vida
    auto life_comp = other->GetComponent<OvejaVegana::LifeComponent>();
    if (life_comp) {
        std::cout << "Curacion cogida y tiene life_comp. Cura: " << std::to_string(amount) << std::endl;

        life_comp->addlife(amount);  // Incrementa la vida del componente de vida encontrado
        //this->GetEntity()->SetActive(false);
        pickedUp = false;

    }

}
void OvejaVegana::HealComponent::OnCollisionExit(VeryReal::Entity* other)
{
    if (!pickedUp)
    {
        this->SetActive(false);
        this->GetEntity()->SetActive(false);
        std::cout << "Curacion borrada" << std::endl;

    }
}
