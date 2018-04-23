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
    virtual void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen){};
    virtual void initKeyboardController(Pacman* pacman){};
    virtual bool running()=0;
    virtual void stop()=0;
    virtual bool timerTicking()=0;
    virtual void timerTicked(){};
    virtual void handleEvents(){};
    virtual void renderClear(){};
    virtual void renderPresent(){};
    virtual void clean(){};
    virtual void showDialog(const char* title, const char* message){};

    //Create the game objects
    virtual Pacman* createPacman(int x, int y, Game* game) = 0;
    virtual Wall* createWall(int x, int y) = 0;
    virtual Ghost* createGhost(int x, int y, Game* game) = 0;
    virtual Bonus* createBonus(int x, int y) = 0;
    virtual Bullet* createBullet(int x, int y) = 0;
    virtual Score* createScore() = 0;
};


#endif //PACMAN_ABSTRACTFACTORY_H
