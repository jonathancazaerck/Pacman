//
// Created by Jonathan Cazaerck on 16/04/18.
//

#ifndef PACMAN_SDLSCORE_H
#define PACMAN_SDLSCORE_H


#include <SDL_render.h>
#include "Score.h"
#include "Constants.h"
namespace SDLPAC {
    class SDLScore : public PAC::Score {
    private:
        int xThousands = 10;
        int xHundards = 16;
        int xTens = 22;
        int xUnits = 28;
        int y = PAC::maxY + 20;

        SDL_Texture *objTexture;
        SDL_Rect srcThousandsRect, srcHundardsRect, srcTensRect, srcUnitRect, destThousandsRect, destHundardsRect, destTensRect, destUnitRect;
        SDL_Renderer *renderer;

        int ySprite = 215;
        int width = 5;
        int height = 7;

        int zeroXpos = 509;
        int oneXpos = 457;
        int twoXpos = 463;
        int threeXpos = 469;
        int fourXpos = 475;
        int fiveXpos = 481;
        int sixXpos = 487;
        int sevenXpos = 492;
        int eightXpos = 498;
        int nineXpos = 504;

        SDL_Rect calcRect(int digit);


    public:
        SDLScore(SDL_Texture *objTexture, SDL_Renderer *renderer);

        void render();

        void visualize();
    };
}


#endif //PACMAN_SDLSCORE_H
