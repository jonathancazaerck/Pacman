//
// Created by Jonathan Cazaerck on 10/04/18.
//

#ifndef PACMAN_SDLBULLET_H
#define PACMAN_SDLBULLET_H

#include "SDLFactory.h"
#include "Bullet.h"

class SDLBullet : public Bullet {
public:
    SDLBullet(int x, int y, const char* texturesheet, SDL_Renderer* renderer);

private:
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};


#endif //PACMAN_SDLBULLET_H
