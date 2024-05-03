#include "CreatorTimerComponent.h"
#include "TimerComponent.h"

VeryReal::Component* OvejaVegana::CreatorTimerComponent::CreatorSpecificComponent()
{
	return new TimerComponent();
}

void OvejaVegana::CreatorTimerComponent::SpecificInitComponent(VeryReal::Component* c)
{
    int maxTime;
    
    OvejaVegana::TimerComponent* tc = static_cast<OvejaVegana::TimerComponent*>(c);

#pragma region Max Time

    if (parameters_map.find("maxTime") != parameters_map.end()) {
        if (std::holds_alternative<int>(parameters_map.at("maxTime")->GetVariant())) {
            maxTime = std::get<int>(parameters_map.at("maxTime")->GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para maxTime, este sera seteado por defecto" << std::endl;
            maxTime = 0;
        }
    }
    else {
        std::cout << "No existe ningun parametro maxTime este sera seteado por defecto" << std::endl;
        maxTime = 0;
    }
#pragma endregion

    if (!tc->InitComponent(maxTime)) {
        // Gestion de error
    }
}