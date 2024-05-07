#include "TimerComponent.h"
#include "UI/UITextComponent.h"
#include "Entity.h"
#include "GameManager.h"
#include <SceneManager.h>
#include <Scene.h>

std::pair<bool, std::string> OvejaVegana::TimerComponent::InitComponent(int maxTime)
{
	time_text = this->GetEntity()->GetComponent<VeryReal::UITextComponent>();
	max_round_time = maxTime;
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
	SetTimerCaption(minutes, seconds);
	if (current_time >= max_round_time) {
		round_completed = true;
		if (OvejaVegana::GameManager::Instance()->GetLevel() == 0) {
			OvejaVegana::GameManager::Instance()->NextLevel();
		}
		else {
			OvejaVegana::GameManager::Instance()->Win();
		}
		
#ifdef _DEBUG
		std::cout << "Round completed  \n";
#endif
	}
}

void OvejaVegana::TimerComponent::GetTimeInMinutesSeconds(int& minutes, int& seconds, float currentTime)
{
	int time = currentTime;
	// Convertir segundos a minutos y segundos
	minutes = time / 60;
	seconds = time % 60;
}

void OvejaVegana::TimerComponent::SetTimerCaption(const int& minutes, const int& seconds)
{	
	std::string minutesWord, secondsWord;
	if (minutes < 10) {
		minutesWord = "0" + std::to_string(minutes);
	}
	else if (minutes <= 0) {
		minutesWord = std::to_string(minutes);
	}
	if (seconds < 10) {
		secondsWord = "0" + std::to_string(seconds);
	}
	else {
		secondsWord = std::to_string(seconds);
	}
	std::string newCaption = " " + minutesWord + " : " + secondsWord;
	time_text->setCaption(newCaption);
}
