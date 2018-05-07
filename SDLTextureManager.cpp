//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLTextureManager.h"
namespace SDLPAC {
    SDL_Texture *SDLTextureManager::LoadTexture(const char *fileName, SDL_Renderer *renderer) {
        SDL_Surface *tempSurface = IMG_Load(fileName);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        return texture;
    }
}