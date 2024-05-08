#include "MenuButtonComponent.h"
#include "GameManager.h"

void OvejaVegana::MenuButtonComponent::Action()
{
	OvejaVegana::GameManager::Instance()->Menu();
}