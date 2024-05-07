#pragma once
#ifndef MUSICBUTTONCOMPONENT
#define MUSICBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

#pragma warning(disable : 4251)

namespace OvejaVegana {
    class OVEJAVEGANA_API MusicButtonComponent : public VeryReal::UIButtonComponent {
    public:      
        virtual void Action(); // M�todo para alternar el estado de la m�sica entre mutear y desmutear
    private:
        bool mute = false;
    };
}

#pragma warning(default : 4251)

#endif
