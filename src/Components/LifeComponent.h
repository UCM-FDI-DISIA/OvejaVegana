#pragma once
#ifndef LIFECOMPONENT
#define LIFECOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "../Export.h"

namespace VeryReal {
	class UIProgressBarComponent;
}
namespace OvejaVegana
{
	class OVEJAVEGANA_API LifeComponent : public VeryReal::Component {
	public:
		//constructora
		LifeComponent();
		//destructora
		virtual ~LifeComponent();
		 bool InitComponent(int max, int initial);
		 //metodo que añade vida y actualiza la progress bar si es que la tiene la entidad
		 void addlife(int toadd);
		 //metodo que decrementa vidas e indica si el personaje sigue vivo
		 bool decreaselife(int todecrease);

	private:
		int maxlife;
		int currentlife;
		bool progressbar;
	};
}
#endif
