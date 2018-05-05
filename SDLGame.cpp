//
// Created by Jonathan Cazaerck on 5/05/18.
//

#include "SDLGame.h"

SDL_Event SDLGame::event;

SDLGame::SDLGame(AbstractFactory *abstractFactory, SDL_Renderer* renderer, SDL_Window* window) : Game::Game(abstractFactory) {
    this->isRunning = true;
    this->renderer = renderer;
    this->window = window;
}

void SDLGame::delay(Uint32 ms){
    SDL_Delay(ms);
}

Uint32 SDLGame::getTimestamp() {
    return SDL_GetTicks();
}

void SDLGame::initKeyboardController(Pacman *pacman) {
    sdlKeyboardController = new SDLKeyboardController(pacman);
}

void SDLGame::handleEvents() {
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

void SDLGame::renderClear() {
    SDL_RenderClear(renderer);
}

void SDLGame::renderPresent(){
    SDL_RenderPresent(renderer);
}

void SDLGame::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;
    std::cout << "Game cleaned" << std::endl;
}

bool SDLGame::getIsRunning(){
    return isRunning;
}

void SDLGame::stopAll(){
    isRunning = false;
}

void SDLGame::showDialog(const char* title, const char* message) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                             title,
                             message,
                             NULL);
}