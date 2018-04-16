//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <iostream>
#include "Player.h"
#include "Game.h"


bool Player::moveUp() {
    if (!changeToUp()) {
        return false;
    }
    y++;
    return true;
}

bool Player::moveDown() {
    if (!changeToDown()) {
        return false;
    }
    y--;
    return true;
}

bool Player::moveLeft() {
    if (!changeToLeft()) {
        return false;
    }
    x--;
    return true;
}

bool Player::moveRight() {
    if (!changeToRight()) {
        return false;
    }
    x++;
    return true;
}

bool Player::changeToUp() {
    if (game->checkOccupiedByWall(this, up)) {
        return false;
    }
    direction = up;
    return true;
}

bool Player::changeToDown() {
    if (game->checkOccupiedByWall(this, down)) {
        return false;
    }
    direction = down;
    return true;
}

bool Player::changeToLeft() {
    if (game->checkOccupiedByWall(this, left)) {
        return false;
    }
    direction = left;
    return true;
}

bool Player::changeToRight() {
//    std::cout << x << "\t" << y << std::endl;
    if (game->checkOccupiedByWall(this, right)) {
        return false;
    }
    direction = right;
    return true;
}

directions Player::getDirection() {
    return direction;
}
