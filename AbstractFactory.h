//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_ABSTRACTFACTORY_H
#define PACMAN_ABSTRACTFACTORY_H


#include <string>
#include "Pacman.h"
#include "Score.h"

class AbstractFactory {
public:
    //Create the game objects
    virtual Pacman* createPacman(int x, int y, Game* game) = 0;
    virtual Wall* createWall(int x, int y) = 0;
    virtual Ghost* createGhost(int x, int y, Game* game) = 0;
    virtual Bonus* createBonus(int x, int y) = 0;
    virtual Bullet* createBullet(int x, int y) = 0;
    virtual Score* createScore() = 0;
    virtual Game* createGame(AbstractFactory*) = 0;
};


#endif //PACMAN_ABSTRACTFACTORY_H
