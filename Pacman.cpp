//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Pacman.h"

Pacman::Pacman(int x, int y) :Player(x,y) {
    direction = left;
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