//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include "SDLFactory.h"
#include "SDLPacman.h"
#include "SDLWall.h"
#include "SDLGhost.h"
#include "SDLBullet.h"
#include "SDLBonus.h"

SDL_Event SDLFactory::event;

SDLFactory::SDLFactory() {
    //
}

void SDLFactory::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if((SDL_Init(SDL_INIT_EVERYTHING)) == 0) {
        std::cout << "Subsystems initialised" << std::endl;
        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if (window)
            std::cout << "Window created" << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            std::cout << "Renderer created" << std::endl;
        }

        objTexture = SDLTextureManager::LoadTexture("../assets/Sprite.png", renderer);
        wallTexture = SDLTextureManager::LoadTexture("../assets/blueWall.png", renderer);

        isRunning = true;
    }

    else { isRunning = false; }
}

void SDLFactory::initKeyboardController(Pacman *pacman) {
    sdlKeyboardController = new SDLKeyboardController(pacman);
}

void SDLFactory::handleEvents() {
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }

    sdlKeyboardController->update();
}

void SDLFactory::renderClear() {
    SDL_RenderClear(renderer);
}

void SDLFactory::renderPresent(){
    SDL_RenderPresent(renderer);
}

void SDLFactory::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;
    std::cout << "Game cleaned" << std::endl;
}


//Create game objects
Pacman* SDLFactory::createPacman(int x, int y, Game* game) {
    return new SDLPacman(x, y, game, objTexture, renderer);
}

Wall* SDLFactory::createWall(int x, int y) {
    return new SDLWall(x, y, wallTexture, renderer);
}

Ghost* SDLFactory::createGhost(int x, int y, Game* game) {
    return new SDLGhost(x, y, game, objTexture, renderer);
}

Bullet* SDLFactory::createBullet(int x, int y) {
    return new SDLBullet(x, y, "dfd", renderer);
}

Bonus* SDLFactory::createBonus(int x, int y) {
    return new SDLBonus(x, y, "dfd", renderer);
}