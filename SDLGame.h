//
// Created by Jonathan Cazaerck on 5/05/18.
//

#ifndef PACMAN_SDLGAME_H
#define PACMAN_SDLGAME_H


#include "AbstractFactory.h"
#include "Game.h"
#include "SDLKeyboardController.h"
#include <SDL2/SDL.h>
namespace SDLPAC {
    class SDLGame : public PAC::Game {
    public:
        SDLGame(PAC::AbstractFactory *abstractFactory, SDL_Renderer *renderer, SDL_Window *window);

        virtual ~SDLGame();

        static SDL_Event event;

    protected:
        void delay(Uint32 ms);

        Uint32 getTimestamp();

        void initKeyboardController(PAC::Pacman *pacman);

        void handleEvents();

        void renderClear();

        void renderPresent();

        void clean();

        bool getIsRunning();

        void stopAll();

        void showDialog(const char *title, const char *message);

    private:
        bool isRunning;
        SDLKeyboardController *sdlKeyboardController;
        SDL_Renderer *renderer;
        SDL_Window *window;
    };
}

#endif //PACMAN_SDLGAME_H
