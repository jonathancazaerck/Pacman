//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLWall.h"
#include "SDLTextureManager.h"


SDLWall::SDLWall(int x, int y, const char *texturesheet, SDL_Renderer *renderer) : Wall(x,y) {
    this->renderer = renderer;
    objTexture = SDLTextureManager::LoadTexture(texturesheet,renderer);
}