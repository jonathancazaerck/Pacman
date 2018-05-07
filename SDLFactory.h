//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_SDLFACTORY_H
#define PACMAN_SDLFACTORY_H


#include "AbstractFactory.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Constants.h"
#include "SDLKeyboardController.h"
#include "SDLInitiator.h"
#include <iostream>
#include <stdint.h>
namespace SDLPAC {
    class SDLKeyboardController;

    class SDLFactory : public PAC::AbstractFactory {
    public:
        SDLFactory(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);

        PAC::Pacman *createPacman(int x, int y, PAC::Game *game);

        PAC::Wall *createWall(int x, int y);

        PAC::Ghost *createGhost(int x, int y, PAC::Game *game);

        PAC::Bonus *createBonus(int x, int y);

        PAC::Bullet *createBullet(int x, int y);

        PAC::Score *createScore();

        PAC::Game *createGame(AbstractFactory *abstractFactory);

        virtual ~SDLFactory();

    private:
        PAC::Game *game;
        SDLKeyboardController *sdlKeyboardController;
        SDLInitiator *sdlInitiator;
        static int event;
    };
}

#endif //PACMAN_SDLFACTORY_H
