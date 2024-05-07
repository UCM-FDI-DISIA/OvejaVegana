#include "ExitButtonComponent.h"
#include "InputManager.h"

void OvejaVegana::ExitButtonComponent::Action()
{
	VeryReal::InputManager::Instance()->Quit(); // Salir de la app
}