//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H


#include <vector>
#include <iostream>
#include <tiff.h>
#include "Pacman.h"
#include "Ghost.h"
#include "Bullet.h"
#include "Wall.h"
#include "AbstractFactory.h"
#include "Score.h"

class Game {
private:
    Pacman* pacman;
    std::vector <Ghost*> ghosts;
    std::vector <Bullet*> bullets;
    std::vector <Wall*> walls;
    std::vector <Bonus*> bonuses;
    void tick();
    void print();
    AbstractFactory* abstractFactory;
    Score* score;
    int killInt;
    uint32 frameStart;
    int frameTime;

protected:
    virtual uint32 getTimestamp()=0;
    virtual void delay(uint32 ms)=0;
    virtual void initKeyboardController(Pacman*)=0;
    virtual void handleEvents()=0;
    virtual void renderClear()=0;
    virtual void renderPresent()=0;
    virtual void clean()=0;
    virtual bool getIsRunning()=0;
    virtual void stopAll()=0;
    virtual void showDialog(const char* title, const char* message)=0;

public:
    Game(AbstractFactory* abstractFactory);
    bool checkOccupiedByWall(Player* player, directions newDirection) const;
    void run();
    void initObjects();
    void gameloop();
};


#endif //PACMAN_GAME_H
