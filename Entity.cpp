//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Entity.h"

Entity::Entity(int x, int y) {
    this->x = x;
    this->y = y;

    std::cout << x << '\t' << y << std::endl;
};

bool Entity::checkCollision(Entity *entity, bool eat, bool bothMoving) {
    bool collision;

    if (!eat && bothMoving) {
        collision = (x == entity->getX() + 1 && y == entity->getY()) ||
                    (x == entity->getX() - 1 && y == entity->getY()) ||
                    (x == entity->getX() && y == entity->getY() + 1) ||
                    (x == entity->getX() && y == entity->getY() - 1) ||
                    (x == entity->getX() + 2 && y == entity->getY()) || //Added because there can be one coordinate between two ghosts.
                    (x == entity->getX() - 2 && y == entity->getY()) || //...when both are moving towards each other they will be at the same
                    (x == entity->getX() && y == entity->getY() + 2) || //...position. We have to prevent that situation.
                    (x == entity->getX() && y == entity->getY() - 2);   //|X|-> <-|X| --- X go towards each other and will have the same position
                                                                        //... when there are odd places between each other.
    } else if (!eat && !bothMoving) {
        collision = (x == entity->getX() + 1 && y == entity->getY()) ||
                    (x == entity->getX() - 1 && y == entity->getY()) ||
                    (x == entity->getX() && y == entity->getY() + 1) ||
                    (x == entity->getX() && y == entity->getY() - 1);
    } else {
        collision = (x == entity->getX() && y == entity->getY());

    }

    return collision;
}

int Entity::getX() {
    return x;
}

int Entity::getY() {
    return y;
}