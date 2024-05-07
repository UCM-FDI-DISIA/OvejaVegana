// OgremanSolucion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <RenderManager.h>

#include "Creator.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Entity.h"
#include "Component.h"

#include "Vector3.h"
#include "SceneManager.h"
#include "ScriptManager.h"
#include "GameManager.h"
#include "CreatorMovementComponent.h"
#include "CreatorPlayerInputComponent.h"
#include "PhysicsManager.h"
#include "PlayButtonComponent.h"
#include "ExitButtonComponent.h"
#include "CreatorExitButtonComponent.h"
#include "CreatorPlayButtonComponent.h"
#include "CreatorEnemyChaseComponent.h"
#include "CreatorMusicButtonComponent.h"
#include "CreatorTimerComponent.h"
#include "CreatorPlayerShootComponent.h"
#include "CreatorLifeComponent.h"
#include "CreatorHealComponent.h"
#include "CreatorBulletComponent.h"
#include "EnemyWaveManager.h"
using namespace VeryReal;

extern "C"  //Para que al exportar la función de las DLLs los nombres no se contaminen (name mangling), esto es usado por el compilador para permitir la sobrecarga de funciones
{
    // Declaración de la función que deseas exportar

    __declspec(dllexport) std::pair<bool, std::string> start() {
        //CREACION DE TODOS LOS COMPONENETES DEL JUEGO
        OvejaVegana::GameManager::Init();
        PhysicsManager::Instance()->SetWorldGravity(Vector3(0, 0, 0));
        //-----//
        VeryReal::Creator::Instance()->AddCreator("EnemyChaseComponent", new OvejaVegana::CreatorEnemyChaseComponent());
        VeryReal::Creator::Instance()->AddCreator("ExitButtonComponent", new OvejaVegana::CreatorExitButtonComponent());
        VeryReal::Creator::Instance()->AddCreator("MovementComponent", new OvejaVegana::CreatorMovementComponent());
        VeryReal::Creator::Instance()->AddCreator("MusicButtonComponent", new OvejaVegana::CreatorMusicButtonComponent());
        VeryReal::Creator::Instance()->AddCreator("PlayButtonComponent", new OvejaVegana::CreatorPlayButtonComponent());
        VeryReal::Creator::Instance()->AddCreator("PlayerInputComponent", new OvejaVegana::CreatorPlayerInputComponent());
        VeryReal::Creator::Instance()->AddCreator("PlayerShootComponent", new OvejaVegana::CreatorPlayerShootComponent());
        VeryReal::Creator::Instance()->AddCreator("TimerComponent", new OvejaVegana::CreatorTimerComponent());
        VeryReal::Creator::Instance()->AddCreator("LifeComponent", new OvejaVegana::CreatorLifeComponent());
        VeryReal::Creator::Instance()->AddCreator("HealComponent", new OvejaVegana::CreatorHealComponent());
        VeryReal::Creator::Instance()->AddCreator("Bullet", new OvejaVegana::CreatorBulletComponent());

        //VeryReal::ScriptManager::Instance()->ExposeFunctionsToLua("Arboles", OvejaVegana::GameManager::Instance()->CreateRandomTrees);
        //VeryReal::ScriptManager::Instance()->ReadFunction();
        return OvejaVegana::GameManager::Instance()->Start();
    }

    __declspec(dllexport) void loop(float dt) {
        OvejaVegana::GameManager::Instance()->Update(dt);
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .slns