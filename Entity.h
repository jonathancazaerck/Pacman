//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

#include "Constants.h"

class Wall;
class Ghost;
class Bullet;
class Pacman;
class Bonus;

class Entity {

protected:
    int x;
    int y;
    int width;
    int height;

public:
    Entity(int x, int y);
    virtual ~Entity(){};
    bool checkCollision(Entity* entity, bool eat, bool bothMoving, directions thisDirection);
    virtual void onCollisionWith(Ghost* ghost){};
    virtual void onCollisionWith(Bullet* bullet){};
    virtual void onCollisionWith(Wall* wall){};
    virtual void onCollisionWith(Pacman* pacman){};
    int getX();
    int getY();
    int getWidth();
    int getHeight();
};


#endif //PACMAN_ENTITY_H
