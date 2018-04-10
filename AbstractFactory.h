//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_ABSTRACTFACTORY_H
#define PACMAN_ABSTRACTFACTORY_H


#include "Pacman.h"

class AbstractFactory {
public:
    virtual void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen){};
    virtual bool running()=0;
    virtual void handleEvents(){};
    virtual void renderClear(){};
    virtual void renderPresent(){};
    virtual void clean(){};

    //Create the game objects
    virtual Pacman* createPacman(int x, int y, Game* game) = 0;
    virtual Wall* createWall(int x, int y) = 0;
    virtual Ghost* createGhost(int x, int y, Game* game) = 0;
    virtual Bonus* createBonus(int x, int y) = 0;
    virtual Bullet* createBullet(int x, int y) = 0;
};


#endif //PACMAN_ABSTRACTFACTORY_H
