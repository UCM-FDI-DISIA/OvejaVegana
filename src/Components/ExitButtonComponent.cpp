#include "ExitButtonComponent.h"
#include "InputManager.h"

bool OvejaVegana::ExitButtonComponent::InitComponent()
{
	return true;
}

void OvejaVegana::ExitButtonComponent::accion()
{
	VeryReal::InputManager::Instance()->Quit(); // Salir de la app
}