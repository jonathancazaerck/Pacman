//
// Created by Jonathan Cazaerck on 11/04/18.
//

#include "SDLKeyboardController.h"

SDLKeyboardController::SDLKeyboardController(Pacman* pacman) {
    this->pacman = pacman;
}

void SDLKeyboardController::update() {
    if (SDLFactory::event.type == SDL_KEYDOWN) {
        switch (SDLFactory::event.key.keysym.sym) {
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