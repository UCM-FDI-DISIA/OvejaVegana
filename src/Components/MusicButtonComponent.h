#pragma once
#include <Component.h>

namespace OvejaVegana {
    class MusicButtonComponent : public VeryReal::Component {
    public:
        MusicButtonComponent() {}
        virtual ~MusicButtonComponent() {}
        bool InitComponent(); // Método para inicializar el componente (e.g., conectar eventos de botón)
        void ToggleMusic();   // Método para alternar el estado de la música entre mutear y desmutear
    private:
        bool mute = false;
    };
}
