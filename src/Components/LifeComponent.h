#pragma once
#ifndef LIFECOMPONENT
#define LIFECOMPONENT

#include "Component.h"
#include "Vector3.h"
#include "../Export.h"

namespace VeryReal {
	class UIProgressBarComponent;
}
namespace OvejaVegana{
	class OVEJAVEGANA_API LifeComponent : public VeryReal::Component {
	public:
	    //constructora
		LifeComponent();
		//destructora
		virtual ~LifeComponent();
		bool InitComponent(float max, float ini);
		//metodo que añade vida y actualiza la progress bar si es que la tiene la entidad
		void addlife(float toadd);
		//metodo que decrementa vidas e indica si el personaje sigue vivo
		bool decreaselife(float todecrease);
		int getMaxLife() {return maxlife; };
		void OnCollisionEnter(VeryReal::Entity* other) override;

	protected:
		float maxlife;
		float currentlife;
		bool progressbar;
		VeryReal::UIProgressBarComponent* my_progress_bar;
	};
}
#endif
