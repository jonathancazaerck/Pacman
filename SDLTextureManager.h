//
// Created by Jonathan Cazaerck on 10/04/18.
//

#ifndef PACMAN_SDLTEXTUREMANAGER_H
#define PACMAN_SDLTEXTUREMANAGER_H

#include "SDLFactory.h"

namespace SDLPAC {
    class SDLTextureManager {
    public:
        static SDL_Texture *LoadTexture(const char *fileName, SDL_Renderer *renderer);
    };
}


#endif //PACMAN_SDLTEXTUREMANAGER_H
