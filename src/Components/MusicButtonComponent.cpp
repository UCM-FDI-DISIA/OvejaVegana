#include "MusicButtonComponent.h"
#include "AudioLeon.h"

void OvejaVegana::MusicButtonComponent::accion() {
	if (!mute) {
		VeryReal::AL().PauseEverySound();
		VeryReal::AL().StopEverySound();
	}
	else {
		VeryReal::AL().ResumeEverySound();
	}
	mute = !mute;
}
