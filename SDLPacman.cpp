//
// Created by Jonathan Cazaerck on 10/04/18.
//

#include "SDLPacman.h"
#include "SDLTextureManager.h"

SDLPacman::SDLPacman(int x, int y, Game* game, SDL_Texture* objTexture, SDL_Renderer* renderer) : Pacman(x,y,game) {
    this->renderer = renderer;
    this->objTexture = objTexture;
    cnt = 0;
}

void SDLPacman::visualize(){
    srcRect.h = 13;
    srcRect.w = 13;

    if(cnt < 5) {

        switch (direction) {
            case right:
                srcRect.x = 457;
                srcRect.y = 1;
                break;

            case left:
                srcRect.x = 457;
                srcRect.y = 17;
                break;

            case up:
                srcRect.x = 457;
                srcRect.y = 49;
                break;

            case down:
                srcRect.x = 457;
                srcRect.y = 33;
                break;
        }
    } else if (cnt < 10) {
        switch (direction) {
            case right:
                srcRect.x = 473;
                srcRect.y = 1;
                break;

            case left:
                srcRect.x = 473;
                srcRect.y = 17;
                break;

            case up:
                srcRect.x = 473;
                srcRect.y = 49;
                break;

            case down:
                srcRect.x = 473;
                srcRect.y = 33;
                break;
        }
    } else if(cnt<15){
        srcRect.x = 489;
        srcRect.y = 1;
    }

    else{cnt=-1;}

    cnt++;

    destRect.h = height;
    destRect.w = width;
    destRect.x = x;
    destRect.y = y;
}

void SDLPacman::render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}