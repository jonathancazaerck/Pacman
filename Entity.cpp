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

    //@todo: geef de richting mee zodat een object langs bvb een muur kan blijven lopen

    bool collision;


    if (eat && bothMoving) {
            collision = x < entity->getX() + entity->getWidth() &&
                        x + width > entity->getX() &&
                        y < entity->getY() + entity->getHeight() &&
                        y + height > entity->getY();

//        collision = (x == entity->getX() && y == entity->getY()) ||
//                    (x == entity->getX() + 1 && y == entity->getY()) ||
//                    (x == entity->getX() - 1 && y == entity->getY()) ||
//                    (x == entity->getX() && y == entity->getY() + 1) ||
//                    (x == entity->getX() && y == entity->getY() - 1);
    } else if (!eat && !bothMoving) {
//        collision = (x == entity->getX() + 1 && y == entity->getY()) ||
//                    (x == entity->getX() - 1 && y == entity->getY()) ||
//                    (x == entity->getX() && y == entity->getY() + 1) ||
//                    (x == entity->getX() && y == entity->getY() - 1);
        int xCheck = x;
        int yCheck = y;

        switch (thisDirection) {
        case up:yCheck = y + 1;
            break;
        case down:yCheck = y - 1;
            break;
        case left:xCheck = x - 1;
            break;
        case right:xCheck = x + 1;
            break;
        }


        bool fullCollision = xCheck < entity->getX() + entity->getWidth() &&
                xCheck + width > entity->getX() &&
                yCheck < entity->getY() + entity->getHeight() &&
                yCheck + height > entity->getY();

        if (!fullCollision) {
//            std::cout << "No" << std::endl;
            return false;
        }
            std::cout << "Yes" << x << "\t" << y << entity->getX() << "\t" << entity->getY() <<  std::endl;

        // there is a collision -> check if collision in correct direction

        //@fixme: Botsing PacMan herstellen
        //@fixme: 1 Ghost gaat uit het scherm en komt op de kader terecht
        switch (thisDirection) {
            case up:
//                collision = (x == entity->getX() && y == entity->getY() - entity->getHeight());
//            collision = (x <= entity->getX() && entity->getX() <= x + width && y <= entity->getY() && entity->getY() <= y + height);
//                collision = (x >= entity->getX() && x <= entity->getX() + entity->getWidth() || x + width >= entity->getX() && x + width <= entity->getX() + entity->getWidth()) && y <= entity->getY();
            collision = y < entity->getY();
//            collision = false;
//                collision = false;
                break;
            case down:
//                collision = (x >= entity->getX() && x <= entity->getX() + entity->getWidth() || x + width >= entity->getX() && x + width <= entity->getX() + entity->getWidth()) && y >= entity->getY();
                collision = y > entity->getY();
//                collision = (x == entity->getX() && y == entity->getY() + entity->getHeight());
//            collision = false;
//            collision = (x <= entity->getX() && entity->getX() <= x + width && y <= entity->getY() && entity->getY() <= y + height);
                break;
            case left:
//                 collision = (x <= entity->getX() && entity->getX() <= x + width && y <= entity->getY() && entity->getY() <= y + height);
//                collision = !(x >= entity->getX() && x <= entity->getX() + entity->getWidth() || x + width >= entity->getX() && x + width <= entity->getX() + entity->getWidth()) && x <= entity->getX();

            collision = x > entity->getX();
//                collision = false;
                break;
            case right:
                collision = x < entity->getX();
//                        !(x >= entity->getX() && x <= entity->getX() + entity->getWidth() || x + width >= entity->getX() && x + width <= entity->getX() + entity->getWidth()) &&
//                collision = (x <= entity->getX() && entity->getX() <= x + width && y <= entity->getY() && entity->getY() <= y + height);
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
