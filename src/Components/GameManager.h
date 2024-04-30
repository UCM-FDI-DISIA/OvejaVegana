#pragma once
#ifndef GAMEMANAGER_OVEJA
#define GAMEMANAGER_OVEJA
#include "Manager.h"
#include "SceneManager.h"

//comentario aclaratorio: contamos con un game manager que llama al SceneManager que tiene una lista de Escenas
namespace OvejaVegana {
	class  GameManager:public VeryReal::Manager<GameManager>
	{
	private:
		GameManager() {}
	public:
		
		virtual ~GameManager();
		void Start();
		void Update(const double& dt);
		void Win();
		void Loose();
		void Menu();
		void Play();
		void Pause();
		static bool Init() {
			GameManager* a = new GameManager();
			if (a != nullptr) {
				instance_pointer.reset(a);
				return true;
			}
			return false;

		}


	};
}



#endif // GAMEMANAGER_OVEJA

