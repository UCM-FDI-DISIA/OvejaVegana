#pragma once
#ifndef TIMERCOMPONENT
#define TIMERCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"

namespace VeryReal {
	class UITextComponent;
}

#pragma warning(disable : 4251)

namespace OvejaVegana {
	class OVEJAVEGANA_API TimerComponent : public VeryReal::Component {
	public:
		virtual std::pair<bool, std::string> InitComponent(int maxTime);
		virtual void Update(const double& dt);
		void GetTimeInMinutesSeconds(int& minutes, int& seconds, float currentTime);
		void SetTimerCaption(const int& minutes, const int& seconds);
	private:
		VeryReal::UITextComponent* time_text = nullptr;
		
		//Variable que almacena el tiempo pasado desde el inicio de la ronda en segundos y milisgeundos
		float current_time = 0;
		//Variable que almacena el tiempo máximo de ronda en segundos.
		int max_round_time;
		//Variable que marca si la ronda ha sido completada
		bool round_completed = false;
	};
}

#pragma warning(default : 4251)

#endif