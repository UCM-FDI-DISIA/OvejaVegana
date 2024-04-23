#include "BulletComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
bool OvejaVegana::BulletComponent::InitComponent()
{
	my_movement_component = this->GetEntity()->GetComponent<OvejaVegana::MovementComponent>();
	

	if (this->my_movement_component != nullptr)
		return true;
	else
		return false;
}


void OvejaVegana::BulletComponent::Update(const double& dt)
{

}

void OvejaVegana::BulletComponent::ShootBullet(VeryReal::Vector3 dir)
{
	
}


void OvejaVegana::BulletComponent::OnCollisionEnter(VeryReal::Entity* other)
{
	if(other->HasComponent("LifeComponent"))
	{
		//GetComponent().doDamage();
	}
}