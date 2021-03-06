//
// Created by Jonathan Cazaerck on 10/04/18.
//

#ifndef PACMAN_SDLWALL_H
#define PACMAN_SDLWALL_H


#include <SDL_render.h>
#include "Wall.h"
namespace SDLPAC {
    class SDLWall : public PAC::Wall {

    public:
        SDLWall(int x, int y, SDL_Texture *objTexture, SDL_Renderer *renderer);

        void visualize();

        void render();

    private:
        SDL_Texture *objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer *renderer;
    };
}


#endif //PACMAN_SDLWALL_H
