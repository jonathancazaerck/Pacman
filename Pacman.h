//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H


#include "Player.h"

class Pacman: public Player {
public:
    Pacman(int x, int y);
    void update();
    void onCollisionWith(Wall *wall);

private:
    void stopMoving();
};


#endif //PACMAN_PACMAN_H
