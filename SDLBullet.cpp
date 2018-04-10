//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLBullet.h"
#include "SDLTextureManager.h"

SDLBullet::SDLBullet(int x, int y, const char *texturesheet, SDL_Renderer *renderer) : Bullet(x,y) {
    this->renderer = renderer;
    objTexture = SDLTextureManager::LoadTexture(texturesheet,renderer);
}