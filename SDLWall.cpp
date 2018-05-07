//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLWall.h"
#include "SDLTextureManager.h"

namespace SDLPAC {
    SDLWall::SDLWall(int x, int y, SDL_Texture *objTexture, SDL_Renderer *renderer) : PAC::Wall(x, y) {
        this->renderer = renderer;
        this->objTexture = objTexture;
    }

    void SDLWall::visualize() {
        srcRect.h = 32;
        srcRect.w = 32;
        srcRect.x = 0;
        srcRect.y = 0;

        destRect.h = height;
        destRect.w = width;
        destRect.x = x;
        destRect.y = y;
    }

    void SDLWall::render() {
        SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
    }
}