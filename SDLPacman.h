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
    SDLPacman(int x, int y, Game* game, const char* texturesheet, SDL_Renderer* renderer);
    void visualize();
    void render();

private:
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

};


#endif //PACMAN_SDLPACMAN_H
