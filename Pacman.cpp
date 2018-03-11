//
// Created by Jonathan Cazaerck on 10/03/18.
//

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
    }
}

//@todo: create stop-function when collision between wall and pacman. Inspiration --> Player.cpp