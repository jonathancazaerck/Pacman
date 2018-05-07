//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLBullet.h"
#include "SDLTextureManager.h"
namespace SDLPAC {
    SDLBullet::SDLBullet(int x, int y, SDL_Texture *objTexture, SDL_Renderer *renderer) : PAC::Bullet(x, y) {
        this->renderer = renderer;
        this->objTexture = objTexture;
    }

    void SDLBullet::visualize() {
        srcRect.h = 10;
        srcRect.w = 10;
        srcRect.x = 63;
        srcRect.y = 159;

        destRect.x = x;
        destRect.y = y;
        destRect.h = height;
        destRect.w = width;
    }

    void SDLBullet::render() {
        SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
    }
}