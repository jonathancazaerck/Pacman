//
// Created by Jonathan Cazaerck on 5/05/18.
//

#ifndef PACMAN_SDLINITIATIOR_H
#define PACMAN_SDLINITIATIOR_H

#include <SDL2/SDL.h>
#include <iostream>


class SDLInitiator {
public:
    bool init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    SDL_Renderer* getRenderer();
    SDL_Texture* getObjTexture();
    SDL_Texture* getWallTexture();
    SDL_Window* getWindow();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *objTexture;
    SDL_Texture *wallTexture;
};


#endif //PACMAN_SDLINITIATIOR_H
