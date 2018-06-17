//
// Created by Jonathan Cazaerck on 5/05/18.
//

#include "SDLGame.h"
namespace SDLPAC {
    SDL_Event SDLGame::event;

    SDLGame::SDLGame(PAC::AbstractFactory *abstractFactory, SDL_Renderer *renderer, SDL_Window *window) : PAC::Game::Game(
            abstractFactory) {
        this->isRunning = true;
        this->renderer = renderer;
        this->window = window;
    }

    void SDLGame::delay(Uint32 ms) {
        SDL_Delay(ms);
    }

    Uint32 SDLGame::getTimestamp() {
        return SDL_GetTicks();
    }

    //Initialize keyboard controller to control the game
    void SDLGame::initKeyboardController(PAC::Pacman *pacman) {
        sdlKeyboardController = new SDLKeyboardController(pacman);
    }

    //Handle events e.g. quit the game or do an action when a key is pressed
    void SDLGame::handleEvents() {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;

            default:
                break;
        }

        //invoke update method from keyboardController to translate a key to an action
        sdlKeyboardController->update();
    }

    void SDLGame::renderClear() {
        SDL_RenderClear(renderer);
    }

    void SDLGame::renderPresent() {
        SDL_RenderPresent(renderer);
    }

    void SDLGame::clean() {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_QUIT;
        std::cout << "Game cleaned" << std::endl;
    }

    bool SDLGame::getIsRunning() {
        return isRunning;
    }

    void SDLGame::stopAll() {
        isRunning = false;
    }

    //Show dialog box
    void SDLGame::showDialog(const char *title, const char *message) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                 title,
                                 message,
                                 NULL);
    }

    SDLGame::~SDLGame() {
        std::cout << "Delete sdlgame:sdlkeyboardcontroller" << std::endl;
        delete sdlKeyboardController;
    }
}
