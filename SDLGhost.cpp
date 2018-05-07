//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLGhost.h"
#include "SDLTextureManager.h"
namespace SDLPAC {
    SDLGhost::SDLGhost(int x, int y, PAC::Game *game, SDL_Texture *objTexture, SDL_Renderer *renderer) : PAC::Ghost(x, y, game) {
        this->renderer = renderer;
        this->objTexture = objTexture;
    }

    void SDLGhost::visualize() {
        if (!enemy) {
            srcRect.h = 14;
            srcRect.w = 14;
            srcRect.x = 585;
            srcRect.y = 65;
        } else {
            srcRect.h = 14;
            srcRect.w = 14;
            srcRect.x = 457;
            srcRect.y = 65;
        }

        destRect.h = height;
        destRect.w = width;
        destRect.x = x;
        destRect.y = y;
    }

    void SDLGhost::render() {
        SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
    }
}