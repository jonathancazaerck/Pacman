//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include "Bullet.h"

Bullet::Bullet(int x, int y) :Entity(x,y) {
    eated = 0;
};

void Bullet::onCollisionWith(Pacman *pacman) {
    eated = 1;
}

bool Bullet::getEated(){
    return eated;
}