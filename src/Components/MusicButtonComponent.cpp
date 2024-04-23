#include "ExitButtonComponent.h"
#include "InputManager.h"
#include "MusicButtonComponent.h"
#include "AudioLeon.h"

bool OvejaVegana::MusicButtonComponent::InitComponent()
{
	return true;
}

void OvejaVegana::MusicButtonComponent::ToggleMusic()
{
	if (!mute)
	{
		VeryReal::AL().PauseEverySound();
		VeryReal::AL().StopEverySound();
	}
	else
	{
		VeryReal::AL().ResumeEverySound();
	}
	mute != mute;
}
