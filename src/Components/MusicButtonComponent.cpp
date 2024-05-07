#include "MusicButtonComponent.h"
#include "AudioManager.h"

void OvejaVegana::MusicButtonComponent::Action() {
	if (!mute) {
		VeryReal::AM().PauseEverySound();
		VeryReal::AM().StopEverySound();
	}
	else {
		VeryReal::AM().ResumeEverySound();
	}
	mute = !mute;
}
