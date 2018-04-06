//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Pacman.h"

Pacman::Pacman(int x, int y, Game* game) :Player(x,y, game) {
    direction = left;
    width = 3;
    height = 3;
};

void Pacman::update() {
    switch(direction){
        case up: moveUp(); break;
        case down: moveDown(); break;
        case left: moveLeft(); break;
        case right: moveRight(); break;
        case stop: stopMoving(); break;
    }
}

void Pacman::stopMoving(){
    direction = stop;
    //don't do anything
}

void Pacman::onCollisionWith(Wall *wall) {
    std::cout<< "On collision with wall/pacman" << std::endl;
    stopMoving();
}