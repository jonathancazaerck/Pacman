//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H


#include "Entity.h"
namespace PAC {
    class Wall : public Entity {
    public:
        Wall(int x, int y);

        virtual void visualize() {};

        virtual void render() {};
    };
}

#endif //PACMAN_WALL_H
