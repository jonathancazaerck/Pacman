//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_SDLFACTORY_H
#define PACMAN_SDLFACTORY_H


#include "AbstractFactory.h"
#include <SDL2/SDL.h>
#include "Constants.h"

class SDLFactory : public AbstractFactory {
public:
    SDLFactory();
    bool init() override ;
    bool loadMedia() override;
    void close() override;

private:
    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = NULL;
    SDL_Surface* gHelloWorld = NULL;
};


#endif //PACMAN_SDLFACTORY_H
