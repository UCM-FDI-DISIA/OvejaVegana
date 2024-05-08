#include "HealComponent.h"
#include "LifeComponent.h" 
#include "PlayerInputComponent.h"


OvejaVegana::HealComponent::HealComponent() {}

OvejaVegana::HealComponent::~HealComponent() {}

std::pair<bool, std::string> OvejaVegana::HealComponent::InitComponent(int amount) {
    pickedUp = false;
    this->amount = amount;
    return { true, "HealComponent created correctly" };
}


void OvejaVegana::HealComponent::OnCollisionEnter(VeryReal::Entity* other) {
    if (other->GetComponent<OvejaVegana::PlayerInputComponent>()) {
        std::cout << "Curacion cogida. Cura: " << std::to_string(amount) << std::endl;
        other->GetComponent<OvejaVegana::LifeComponent>()->addlife(amount);  // Incrementa la vida del componente de vida encontrado
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
