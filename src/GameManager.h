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
		int level = 0;
	public:
		static bool Init() {
			GameManager* a = new GameManager();
			if (a != nullptr) {
				instance_pointer.reset(a);
				return true;
			}
			return false;
		}
		virtual ~GameManager();
		std::pair<bool, std::string> Start();
		
		void Win();
		void NextLevel();
		void Lose();
		void Menu();
		void Play();

		int GetLevel();

		static void CreateRandomTrees();
	};
}



#endif // GAMEMANAGER_OVEJA

