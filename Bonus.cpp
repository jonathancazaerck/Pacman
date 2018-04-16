//
// Created by Jonathan Cazaerck on 12/03/18.
//

#include "Bonus.h"


Bonus::Bonus(int x, int y) : Bullet(x, y) {
    active = false;
    width = 8;
    height = 8;
};

void Bonus::onCollisionWith(Pacman *pacman) {
    eated = true;
    active = true;
}

bool Bonus::isActive() {
    return active;
}

void Bonus::setDeactive() {
    active = false;
}
