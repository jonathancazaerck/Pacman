//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLGhost.h"
#include "SDLTextureManager.h"

SDLGhost::SDLGhost(int x, int y, Game* game, const char *texturesheet, SDL_Renderer *renderer) : Ghost(x,y,game) {
    this->renderer = renderer;
    objTexture = SDLTextureManager::LoadTexture(texturesheet,renderer);
}