//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLBonus.h"
#include "SDLTextureManager.h"
namespace SDLPAC {
    SDLBonus::SDLBonus(int x, int y, SDL_Texture *objTexture, SDL_Renderer *renderer) : PAC::Bonus(x, y) {
        this->renderer = renderer;
        this->objTexture = objTexture;
    }

    void SDLBonus::visualize() {
        srcRect.h = 8;
        srcRect.w = 8;
        srcRect.x = 8;
        srcRect.y = 184;

        destRect.x = x;
        destRect.y = y;
        destRect.h = height;
        destRect.w = width;
    }

    void SDLBonus::render() {
        SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
    }
}