#include "CreatorBulletComponent.h"
#include "BulletComponent.h"

VeryReal::Component* OvejaVegana::CreatorBulletComponent::CreatorSpecificComponent()
{
    return new BulletComponent();
}

void OvejaVegana::CreatorBulletComponent::SpecificInitComponent(VeryReal::Component* c)
{
    OvejaVegana::BulletComponent* bullet_comp = static_cast<OvejaVegana::BulletComponent*>(c);

    if (!bullet_comp->InitComponent()) {

    }
}

void OvejaVegana::CreatorBulletComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    int a = 0;
    BulletComponent* t = static_cast<BulletComponent*>(c);
    BulletComponent* copia = static_cast<BulletComponent*>(other);
    bool b = t->InitComponent();
    if (!b) {
    }
}