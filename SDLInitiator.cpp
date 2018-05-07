//
// Created by Jonathan Cazaerck on 5/05/18.
//

#include "SDLInitiator.h"
#include "SDLTextureManager.h"
namespace SDLPAC {
    bool SDLInitiator::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
        int flags = 0;
        if (fullscreen)
            flags = SDL_WINDOW_FULLSCREEN;

        if ((SDL_Init(SDL_INIT_EVERYTHING)) == 0) {
            std::cout << "Subsystems initialised" << std::endl;
            window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

            if (window)
                std::cout << "Window created" << std::endl;

            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                std::cout << "Renderer created" << std::endl;
            }

            objTexture = SDLTextureManager::LoadTexture("../assets/Sprite.png", renderer);
            wallTexture = SDLTextureManager::LoadTexture("../assets/blueWall.png", renderer);

            return true;
        } else { return false; }
    }

    SDL_Renderer *SDLInitiator::getRenderer() {
        return renderer;
    }

    SDL_Texture *SDLInitiator::getObjTexture() {
        return objTexture;
    }

    SDL_Texture *SDLInitiator::getWallTexture() {
        return wallTexture;
    }

    SDL_Window *SDLInitiator::getWindow() {
        return window;
    }

    SDLInitiator::~SDLInitiator() {
        std::cout << "Delete sdlfactory:sdlinitiator:renderer" << std::endl;
        SDL_DestroyRenderer(renderer);
        std::cout << "Delete sdlfactory:sdlinitiator:objtexture" << std::endl;
        SDL_DestroyTexture(objTexture);
        std::cout << "Delete sdlfactory:sdlinitiator:walltexture" << std::endl;
        SDL_DestroyTexture(wallTexture);
        std::cout << "Delete sdlfactory:sdlinitiator:window" << std::endl;
        SDL_DestroyWindow(window);
    }
}
