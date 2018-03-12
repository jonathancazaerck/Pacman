//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Ghost.h"

Ghost::Ghost(int x, int y) : Player(x, y) {
    enemy = false;
    direction = left;
    noEnemyLifetime = 0;
};

void Ghost::update() {
    if (!enemy){
        noEnemyLifetime--;
        std::cout << noEnemyLifetime << std::endl;
    }

    if (noEnemyLifetime < 0){
        enemy = true;
        std::cout << "Time's up!" << std::endl;
    }


    switch (direction) {
        case up:
            moveUp();
            break;
        case down:
            moveDown();
            break;
        case left:
            moveLeft();
            break;
        case right:
            moveRight();
            break;
    }
}

void Ghost::onCollisionWith(Wall *wall) {
    //Clockwise if there is a collision between the ghost and the walls
    switch (direction) {
        case up:
            moveLeft();
            break;
        case down:
            moveRight();
            break;
        case left:
            moveDown();
            break;
        case right:
            moveUp();
            break;
    }
}

//DELETED: COLLISION BETWEEN TWO GHOSTS = NOT NECESSARY
//void Ghost::onCollisionWith(Ghost *ghost) {
//    std::cout << "collision with ghost" << std::endl;
//    switch (direction) {
//        case up:
//            moveDown();
//            break;
//        case down:
//            moveUp();
//            break;
//        case left:
//            moveRight();
//            break;
//        case right:
//            moveLeft();
//            break;
//    }
//}

bool Ghost::getEnemy() {
    return enemy;
}

void Ghost::setNotEnemy() {
    std::cout << "Set not enemy" << std::endl;
    this->enemy = false;
    noEnemyLifetime = 5;
}