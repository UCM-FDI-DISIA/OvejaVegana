#include "ExitButtonComponent.h"
#include "InputManager.h"

void OvejaVegana::ExitButtonComponent::accion()
{
	VeryReal::InputManager::Instance()->Quit(); // Salir de la app
}