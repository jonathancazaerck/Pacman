//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H


#include "Constants.h"
#include "Entity.h"

class Player : public Entity {
protected:
    directions direction;
public:
    directions getDirection();

public:
    Player(int x, int y):Entity(x,y){};
    virtual ~Player(){};
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    virtual void update(){};
};


#endif //PACMAN_PLAYER_H
