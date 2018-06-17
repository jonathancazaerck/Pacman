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

    //Ghost time count down if not an enemy when lifetime = 0 he will be back an enemy
    //Ghost change direction update
    void Ghost::update() {
        if (!enemy) {
            noEnemyLifetime--;
        }

        if (noEnemyLifetime < 0) {
            enemy = true;
            bonusGetted = false;
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

    //Method to run when there is a collision
    void Ghost::onCollisionWith(Wall *wall) {
        //Clockwise choosing direction if there is a collision between the ghost and the walls
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
                    break;
                } else if (changeToDown()) {
                    break;
                } else if (changeToRight()) {
                    break;
                } else if (changeToLeft()) {
                    break;
                }
        }
    }

    bool Ghost::getEnemy() {
        return enemy;
    }

    void Ghost::setNotEnemy() {
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
