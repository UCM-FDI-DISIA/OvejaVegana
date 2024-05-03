#include "TimerComponent.h"
#include "UI/UITextComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <Scene.h>

bool OvejaVegana::TimerComponent::InitComponent()
{
	time_text = this->GetEntity()->GetComponent<VeryReal::UITextComponent>();
	max_round_time = 180;
	if (time_text != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void OvejaVegana::TimerComponent::Update(const double& dt)
{
	int minutes, seconds;
	current_time += dt;
	GetTimeInMinutesSeconds(minutes, seconds, current_time);
	SetTimerCaption(std::to_string(minutes), std::to_string(seconds));
	if (current_time >= max_round_time) {
		round_completed = true;
	}
}

void OvejaVegana::TimerComponent::GetTimeInMinutesSeconds(int& minutes, int& seconds, float currentTime)
{
	int time = currentTime;
	// Convertir segundos a minutos y segundos
	minutes = time / 60;
	seconds = time % 60;
}

void OvejaVegana::TimerComponent::SetTimerCaption(const std::string& minutes, const std::string& seconds)
{
	std::string newCaption = " " + minutes + " : " + seconds;
	time_text->setCaption(newCaption);
}
