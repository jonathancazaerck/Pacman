//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Ghost.h"
namespace PAC {
    Ghost::Ghost(int x, int y, Game *game) : Player(x, y, game) {
        enemy = false;
        bonusGetted = false;
        direction = left;
        noEnemyLifetime = 0;
        defaultX = x;
        defaultY = y;
    };

    void Ghost::update() {
        if (!enemy) {
            noEnemyLifetime--;
//        std::cout << noEnemyLifetime << std::endl;
        }

        if (noEnemyLifetime < 0) {
            enemy = true;
            bonusGetted = false;
//        std::cout << "Time's up!" << std::endl;
        }

//    std::cout << "dir " << direction << std::endl;

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
//    std::cout << "collision" << std::endl;
        directions randomDirection = static_cast<directions>(rand() % right);
        switch (randomDirection) {
            case up:
                if (changeToLeft()) {
                    break;
                }
            case down:
                if (changeToRight()) {
                    break;
                }
            case left:
                if (changeToDown()) {
                    break;
                }
            case right:
                if (changeToUp()) {
                    //std::cout << "change up " << direction << std::endl;
                    break;
                } else if (changeToDown()) {
                    //std::cout << "change down " << std::endl;
                    break;
                } else if (changeToRight()) {
                    //std::cout << "change right" << std::endl;
                    break;
                } else if (changeToLeft()) {
                    //std::cout << "change left" << std::endl;
                    break;
                }
        }
    }

    bool Ghost::getEnemy() {
        return enemy;
    }

    void Ghost::setNotEnemy() {
        //std::cout << "Set not enemy" << std::endl;
        this->enemy = false;
        noEnemyLifetime = 1000;
    }

    void Ghost::setBonusGetted() {
        this->bonusGetted = true;
    }

    bool Ghost::getBonusGetted() {
        return bonusGetted;
    }

    void Ghost::resetPosition() {
        x = defaultX;
        y = defaultY;
    }

    Ghost::~Ghost() {

    }
}