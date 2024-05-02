#include "MusicButtonComponent.h"
#include "AudioManager.h"

void OvejaVegana::MusicButtonComponent::accion() {
	if (!mute) {
		VeryReal::AM().PauseEverySound();
		VeryReal::AM().StopEverySound();
	}
	else {
		VeryReal::AM().ResumeEverySound();
	}
	mute = !mute;
}
