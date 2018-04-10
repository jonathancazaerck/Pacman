//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLBonus.h"
#include "SDLTextureManager.h"

SDLBonus::SDLBonus(int x, int y, const char *texturesheet, SDL_Renderer *renderer) : Bonus(x,y) {
    this->renderer = renderer;
    objTexture = SDLTextureManager::LoadTexture(texturesheet,renderer);
}