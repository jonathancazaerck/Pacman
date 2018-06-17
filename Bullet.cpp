//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include "Bullet.h"

namespace PAC {

    Bullet::Bullet(int x, int y) : Entity(x, y) {
        width = 10;
        height = 10;
    };

    void Bullet::onCollisionWith(Pacman *pacman) {
        //
    }
}
