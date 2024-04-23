#pragma once
#include <Component.h>

namespace OvejaVegana {
    class MusicButtonComponent : public VeryReal::Component {
    public:
        MusicButtonComponent() {}
        virtual ~MusicButtonComponent() {}
        bool InitComponent(); // M�todo para inicializar el componente (e.g., conectar eventos de bot�n)
        void ToggleMusic();   // M�todo para alternar el estado de la m�sica entre mutear y desmutear
    private:
        bool mute = false;
    };
}
