//
// Created by Jonathan Cazaerck on 10/04/18.
//

#ifndef PACMAN_SDLPACMAN_H
#define PACMAN_SDLPACMAN_H

#include "SDLFactory.h"
#include "SDLTextureManager.h"
#include "Pacman.h"

class SDLPacman : public Pacman {
public:
    SDLPacman(int x, int y, Game* game, SDL_Texture* objTexture, SDL_Renderer* renderer);
    void visualize();
    void render();
    void kill(int i);

private:
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
    int cnt;

};


#endif //PACMAN_SDLPACMAN_H
