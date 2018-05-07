//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_BULLET_H
#define PACMAN_BULLET_H


#include "Pacman.h"

namespace PAC {

    class Bullet : public Entity {
    public:
        Bullet(int x, int y);

        void onCollisionWith(Pacman *pacman);

        virtual void visualize() {};

        virtual void render() {};
    };

}
#endif //PACMAN_BULLET_H
