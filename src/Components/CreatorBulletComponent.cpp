#include "CreatorBulletComponent.h"
#include "BulletComponent.h"

VeryReal::Component* OvejaVegana::CreatorBulletComponent::CreatorSpecificComponent()
{
    return new BulletComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorBulletComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::BulletComponent* bullet_comp = static_cast<OvejaVegana::BulletComponent*>(c);

    return bullet_comp->InitComponent();
}

std::pair<bool, std::string> OvejaVegana::CreatorBulletComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    int a = 0;
    BulletComponent* t = static_cast<BulletComponent*>(c);
    BulletComponent* copia = static_cast<BulletComponent*>(other);
    return t->InitComponent();
}