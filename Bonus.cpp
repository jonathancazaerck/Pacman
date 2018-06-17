//
// Created by Jonathan Cazaerck on 12/03/18.
//

#include "Bonus.h"

namespace PAC {
    Bonus::Bonus(int x, int y) : Bullet(x, y) {
        active = false;
        width = 8;
        height = 8;
    };

    //Method to run when there is a collision
    void Bonus::onCollisionWith(Pacman *pacman) {
        active = true;
    }

    bool Bonus::isActive() {
        return active;
    }

    void Bonus::setDeactive() {
        active = false;
    }
}
