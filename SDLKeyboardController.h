//
// Created by Jonathan Cazaerck on 11/04/18.
//

#ifndef PACMAN_SDLKEYBOARDCONTROLLER_H
#define PACMAN_SDLKEYBOARDCONTROLLER_H


#include "SDLPacman.h"
namespace SDLPAC {
    class SDLKeyboardController {
    public:
        PAC::Pacman *pacman;

        SDLKeyboardController(PAC::Pacman *pacman);

        void update();
    };
}


#endif //PACMAN_SDLKEYBOARDCONTROLLER_H
