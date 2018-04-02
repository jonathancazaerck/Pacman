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
    bool pollEvent() override ;

private:
    SDL_Window* gWindow = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* gScreenSurface = NULL;
    SDL_Surface* gCurrentSurface = NULL;
    SDL_Event e;
    enum KeyPressSurfaces
    {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };
    SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
};


#endif //PACMAN_SDLFACTORY_H
