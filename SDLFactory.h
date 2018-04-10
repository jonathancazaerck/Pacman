//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_SDLFACTORY_H
#define PACMAN_SDLFACTORY_H


#include "AbstractFactory.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Constants.h"
#include <iostream>

class SDLFactory : public AbstractFactory {
public:
    SDLFactory();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void handleEvents();

    void renderClear();

    void renderPresent();

    void clean();

    bool running() { return  isRunning; }

    Pacman* createPacman(int x, int y, Game* game);
    Wall* createWall(int x, int y);
    Ghost* createGhost(int x, int y, Game* game);
    Bonus* createBonus(int x, int y);
    Bullet* createBullet(int x, int y);

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //PACMAN_SDLFACTORY_H
