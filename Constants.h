//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_CONSTANTS_H
#define PACMAN_CONSTANTS_H

namespace PAC {
    const int maxY = 480;
    const int minY = 0;
    const int maxX = 370;
    const int minX = 0;
    const int bulletStep = 30;
    const int wallStep = 1;
    const int playerHeight = 18;
    const int playerWidth = 18;

    const int SCREEN_WIDTH = 380;
    const int SCREEN_HEIGHT = 510;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    enum directions {
        up, down, left, right, stop
    };
}
#endif //PACMAN_CONSTANTS_H
