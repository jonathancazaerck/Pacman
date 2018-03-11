//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_BULLET_H
#define PACMAN_BULLET_H


#include "Pacman.h"

class Bullet : public Entity {
private:
    bool eated;
public:
    Bullet(int x, int y);
    void onCollisionWith(Pacman* pacman);
    bool getEated();
};


#endif //PACMAN_BULLET_H
