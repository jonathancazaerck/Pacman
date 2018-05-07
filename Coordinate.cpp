//
// Created by Jonathan Cazaerck on 6/04/18.
//

#include "Coordinate.h"
namespace PAC {
    Coordinate::Coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    };

    int Coordinate::getX() {
        return x;
    }

    int Coordinate::getY() {
        return y;
    }

    void Coordinate::setDirection(directions direction) {
        this->direction = direction;
    }

    directions Coordinate::getDirection() {
        return direction;
    }
}