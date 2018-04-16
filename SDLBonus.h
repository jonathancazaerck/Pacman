//
// Created by Jonathan Cazaerck on 10/04/18.
//

#ifndef PACMAN_SDLBONUS_H
#define PACMAN_SDLBONUS_H


#include "Bonus.h"
#include "SDLFactory.h"

class SDLBonus : public Bonus {
public:
    SDLBonus(int x, int y, SDL_Texture* objTexture, SDL_Renderer* renderer);
    void visualize();
    void render();

private:
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};


#endif //PACMAN_SDLBONUS_H
