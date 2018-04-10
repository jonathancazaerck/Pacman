//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLPacman.h"
#include "SDLTextureManager.h"

SDLPacman::SDLPacman(int x, int y, Game* game, const char* texturesheet, SDL_Renderer* renderer) : Pacman(x,y,game) {
    this->renderer = renderer;
    objTexture = SDLTextureManager::LoadTexture(texturesheet,this->renderer);
}

void SDLPacman::visualize(){
    srcRect.h = 128;
    srcRect.w = 128;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = height;
    destRect.w = width;
    destRect.x = x;
    destRect.y = y;
}

void SDLPacman::render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}