//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

class Wall;
class Ghost;
class Bullet;

class Entity {

protected:
    int x;
    int y;

public:
    Entity(int x, int y);
    virtual ~Entity(){};
    bool checkCollision(Entity* entity, bool eat, bool bothMoving);
    virtual void onCollisionWith(Ghost* ghost){};
    virtual void onCollisionWith(Bullet* bullet){};
    virtual void onCollisionWith(Wall* wall){};
    int getX();
    int getY();
};


#endif //PACMAN_ENTITY_H
