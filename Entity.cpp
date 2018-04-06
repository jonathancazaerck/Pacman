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

bool Entity::checkCollision(Entity *entity, bool eat, bool bothMoving, directions thisDirection) {

    bool collision;


    if (eat && bothMoving) {
        collision = x < entity->getX() + entity->getWidth() &&
                    x + width > entity->getX() &&
                    y < entity->getY() + entity->getHeight() &&
                    y + height > entity->getY();

    } else if (!eat && !bothMoving) {
        int xCheck = x;
        int yCheck = y;

        switch (thisDirection) {
            case up:
                yCheck = y + 1;
                break;
            case down:
                yCheck = y - 1;
                break;
            case left:
                xCheck = x - 1;
                break;
            case right:
                xCheck = x + 1;
                break;
        }


        bool fullCollision = xCheck < entity->getX() + entity->getWidth() &&
                             xCheck + width > entity->getX() &&
                             yCheck < entity->getY() + entity->getHeight() &&
                             yCheck + height > entity->getY();

        if (!fullCollision) {
            return false;
        }

        // there is a collision -> check if collision in correct direction

        //@fixme: Botsing PacMan herstellen
        switch (thisDirection) {
            case up:
                collision = y < entity->getY();
                break;
            case down:
                collision = y > entity->getY();
                break;
            case left:
                collision = x > entity->getX();
                break;
            case right:
                collision = x < entity->getX();
                break;
        }
        if (collision) {
            std::cout << "collision in directionn" << std::endl;
        }
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

int Entity::getWidth() {
    return width;
}

int Entity::getHeight() {
    return height;
}
