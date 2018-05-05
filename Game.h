//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H


#include <vector>
#include <iostream>
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

public:
    Game(AbstractFactory* abstractFactory);
    bool checkOccupiedByWall(Player* player, directions newDirection) const;
    void run();
    void initObjects();
    void gameloop();


};


#endif //PACMAN_GAME_H
