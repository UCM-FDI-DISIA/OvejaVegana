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
#include "../Components/CreatorMovementComponent.h"
#include "../Components/CreatorPlayerInputComponent.h"
#include "PhysicsManager.h"
#include "../Components/PlayButtonComponent.h"
#include "../Components/ExitButtonComponent.h"
#include "../Components/CreatorExitButtonComponent.h"
#include "../Components/CreatorPlayButtonComponent.h"


using namespace VeryReal;

extern "C"  //Para que al exportar la función de las DLLs los nombres no se contaminen (name mangling), esto es usado por el compilador para permitir la sobrecarga de funciones
{
    // Declaración de la función que deseas exportar

    __declspec(dllexport) bool start() {
        //CREACION DE TODOS LOS COMPONENETES DEL JUEGO

        ScriptManager::Instance()->ReadScene("HouseScene");
        VeryReal::SceneManager::Instance()->GetScene("HouseScene")->SetActive(true);
        return true;
    }

    __declspec(dllexport) void loop()
    {
        /*  std::cout << "Pepa" << std::endl;*/
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