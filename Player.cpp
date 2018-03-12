//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include "Player.h"


void Player::moveUp() {
    direction = up;
    y++;
}

void Player::moveDown() {
    direction = down;
    y--;
}

void Player::moveLeft() {
    direction = left;
    x--;
}

void Player::moveRight() {
    direction = right;
    x++;
}

directions Player::getDirection() {
    return direction;
}
