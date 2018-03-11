//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Ghost.h"

Ghost::Ghost(int x, int y) :Player(x,y) {
    direction = left;
};

void Ghost::update() {
    switch(direction){
        case up: moveUp(); break;
        case down: moveDown(); break;
        case left: moveLeft(); break;
        case right: moveRight(); break;
    }
    std::cout << direction << std::endl;
}

void Ghost::onCollisionWith(Wall* wall){
    switch(direction){
        case up: moveDown(); break;
        case down: moveUp(); break;
        case left: moveRight(); break;
        case right: moveLeft(); break;
    }
}

void Ghost::onCollisionWith(Ghost* ghost){
    std::cout << "collision with ghost"  << std::endl;
    switch(direction){
        case up: moveDown(); break;
        case down: moveUp(); break;
        case left: moveRight(); break;
        case right: moveLeft(); break;
    }
}