//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Entity.h"
namespace PAC {
    Entity::Entity(int x, int y) {
        this->x = x;
        this->y = y;
    };

    //Method to check if there is a collision
    bool Entity::checkCollision(Entity *entity, bool eat, bool bothMoving, directions thisDirection) {

        bool collision;

        //If this object is allowed to eat the other object
        if (eat) {
            collision = x < entity->getX() + entity->getWidth() &&
                        x + width > entity->getX() &&
                        y < entity->getY() + entity->getHeight() &&
                        y + height > entity->getY();

        }

        //If this object is not allowed to eat the other object and both objects are not moving
        else if (!eat && !bothMoving) {
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

            //Check if there will be a collision in any of the four directions
            bool fullCollision = xCheck < entity->getX() + entity->getWidth() &&
                                 xCheck + width > entity->getX() &&
                                 yCheck < entity->getY() + entity->getHeight() &&
                                 yCheck + height > entity->getY();


            //If no collision in any of the four direction -> return false
            if (!fullCollision) {
                return false;
            } else {
            	//
            }

            //There is a collision in any of the four directions. Check if collision in correct direction
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
                case stop:
                    collision = true;
                    break;


            }
            if (collision) {
            	//
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
}
