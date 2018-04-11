//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H


#include "Constants.h"
#include "Entity.h"

class Game;

class Player : public Entity {
protected:
    directions direction;
public:
    directions getDirection();

public:
    Player(int x, int y, Game* game):Entity(x,y){
            this->game = game;
            width = 18;
            height = 18;
    };
    virtual ~Player(){};
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();

    bool changeToUp();
    bool changeToDown();
    bool changeToLeft();
    bool changeToRight();
    virtual void update(){};
private:
    Game* game;
};


#endif //PACMAN_PLAYER_H
