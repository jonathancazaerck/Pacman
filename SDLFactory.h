//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_SDLFACTORY_H
#define PACMAN_SDLFACTORY_H


#include "AbstractFactory.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Constants.h"
#include "SDLKeyboardController.h"
#include <iostream>
#include <stdint.h>

class SDLKeyboardController;

class SDLFactory : public AbstractFactory {
public:
    SDLFactory();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void initKeyboardController(Pacman* pacman);

    void handleEvents();

    void renderClear();

    void renderPresent();

    void clean();

    bool running() { return  isRunning; }

    bool timerTicking() { return  timerTick; }

    void timerTicked();

    void stop();

    void showDialog(const char* title, const char* message);

    Pacman* createPacman(int x, int y, Game* game);
    Wall* createWall(int x, int y);
    Ghost* createGhost(int x, int y, Game* game);
    Bonus* createBonus(int x, int y);
    Bullet* createBullet(int x, int y);
    Score* createScore();

    static SDL_Event event;
    static SDL_UserEvent userEvent;

private:
    bool isRunning;
    bool timerTick = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture* objTexture;
    SDL_Texture* wallTexture;
    //Uint32 timerCallback(Uint32 interval, void *param);

    SDLKeyboardController *sdlKeyboardController;
};


#endif //PACMAN_SDLFACTORY_H
