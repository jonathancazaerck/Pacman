//
// Created by Jonathan Cazaerck on 10/04/18.
//

#ifndef PACMAN_SDLGHOST_H
#define PACMAN_SDLGHOST_H

#include "SDLFactory.h"
#include "Ghost.h"
namespace SDLPAC {
    class SDLGhost : public PAC::Ghost {
    public:
        SDLGhost(int x, int y, PAC::Game *game, SDL_Texture *objTexture, SDL_Renderer *renderer);

        void visualize();

        void render();

    private:
        SDL_Texture *objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer *renderer;
    };
}

#endif //PACMAN_SDLGHOST_H
