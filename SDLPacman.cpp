//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLPacman.h"
#include "SDLTextureManager.h"

SDLPacman::SDLPacman(int x, int y, Game* game, SDL_Texture* objTexture, SDL_Renderer* renderer) : Pacman(x,y,game) {
    this->renderer = renderer;
    this->objTexture = objTexture;
}

void SDLPacman::visualize(){
    srcRect.h = 13;
    srcRect.w = 13;
    srcRect.x = 473;
    srcRect.y = 1;

    destRect.h = height;
    destRect.w = width;
    destRect.x = x;
    destRect.y = y;
}

void SDLPacman::render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}