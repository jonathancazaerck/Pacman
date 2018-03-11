//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H


#include <vector>
#include "Pacman.h"
#include "Ghost.h"
#include "Bullet.h"
#include "Wall.h"

class Game {
private:
    Pacman* pacman;
    std::vector <Ghost*> ghosts;
    std::vector <Bullet*> bullets;
    std::vector <Wall*> walls;
    void tick();
    void print();

public:
    Game();
    void run();
};


#endif //PACMAN_GAME_H
