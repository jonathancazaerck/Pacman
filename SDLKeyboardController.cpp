//
// Created by Jonathan Cazaerck on 11/04/18.
//

#include "SDLKeyboardController.h"
#include "SDLGame.h"
namespace SDLPAC {
    SDLKeyboardController::SDLKeyboardController(PAC::Pacman *pacman) {
        this->pacman = pacman;
    }

    void SDLKeyboardController::update() {
        if (SDLGame::event.type == SDL_KEYDOWN) {
            switch (SDLGame::event.key.keysym.sym) {
                case SDLK_DOWN:
                    pacman->moveUp();
                    break;

                case SDLK_UP:
                    pacman->moveDown();
                    break;

                case SDLK_LEFT:
                    pacman->moveLeft();
                    break;

                case SDLK_RIGHT:
                    pacman->moveRight();
                    break;

                default:
                    break;

            }
        }
    }
}