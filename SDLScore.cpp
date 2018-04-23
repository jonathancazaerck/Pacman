//
// Created by Jonathan Cazaerck on 16/04/18.
//

#include <iostream>
#include "SDLScore.h"

SDLScore::SDLScore(SDL_Texture* objTexture, SDL_Renderer *renderer) : Score() {
    this->renderer = renderer;
    this->objTexture = objTexture;
}

void SDLScore::visualize(){


    //std::cout<<score<<std::endl;

    srcThousandsRect = calcRect(score/1000);
    srcHundardsRect = calcRect((score/100)%10);
    srcTensRect = calcRect((score/10)%10);
    srcUnitRect = calcRect(score%10);



    destThousandsRect.h = height;
    destThousandsRect.w = width;
    destThousandsRect.x = xThousands;
    destThousandsRect.y = y;

    destHundardsRect.h = height;
    destHundardsRect.w = width;
    destHundardsRect.x = xHundards;
    destHundardsRect.y = y;

    destTensRect.h = height;
    destTensRect.w = width;
    destTensRect.x = xTens;
    destTensRect.y = y;

    destUnitRect.h = height;
    destUnitRect.w = width;
    destUnitRect.x = xUnits;
    destUnitRect.y = y;
}

void SDLScore::render() {
    SDL_RenderCopy(renderer, objTexture, &srcThousandsRect, &destThousandsRect);
    SDL_RenderCopy(renderer, objTexture, &srcHundardsRect, &destHundardsRect);
    SDL_RenderCopy(renderer, objTexture, &srcTensRect, &destTensRect);
    SDL_RenderCopy(renderer, objTexture, &srcUnitRect, &destUnitRect);
}

SDL_Rect SDLScore::calcRect(int digit) {
    //std::cout << "input SDLScore, digit is: " << digit << std::endl;
    SDL_Rect srcRect;
    srcRect.w = width;
    srcRect.h = height;
    srcRect.y = ySprite;
    switch (digit){
        case 1:
            srcRect.x = oneXpos;
            break;

        case 2:
            srcRect.x = twoXpos;
            break;

        case 3:
            srcRect.x = threeXpos;
            break;

        case 4:
            srcRect.x = fourXpos;
            break;

        case 5:
            srcRect.x = fiveXpos;
            break;

        case 6:
            srcRect.x = sixXpos;
            break;

        case 7:
            srcRect.x = sevenXpos;
            break;

        case 8:
            srcRect.x = eightXpos;
            break;

        case 9:
            srcRect.x = nineXpos;
            break;

        case 0:
            srcRect.x = zeroXpos;
            break;

        default:
        std::cout << "Problem with SDLScore, digit is: " << digit << std::endl;

    }

    return srcRect;
}