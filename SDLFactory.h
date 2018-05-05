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

class SDLKeyboardController;

class SDLFactory : public AbstractFactory {
public:
    SDLFactory(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    Pacman* createPacman(int x, int y, Game* game);
    Wall* createWall(int x, int y);
    Ghost* createGhost(int x, int y, Game* game);
    Bonus* createBonus(int x, int y);
    Bullet* createBullet(int x, int y);
    Score* createScore();
    Game* createGame(AbstractFactory* abstractFactory);

private:
    Game* game;
    SDLKeyboardController *sdlKeyboardController;
    SDLInitiator* sdlInitiator;
    static int event;
};


#endif //PACMAN_SDLFACTORY_H
