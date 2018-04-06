//
// Created by Jonathan Cazaerck on 6/04/18.
//

#ifndef PACMAN_COORDINATE_H
#define PACMAN_COORDINATE_H


#include <string>
#include "Constants.h"

class Coordinate {
private:
    int x;
    int y;
    directions direction;

public:
    Coordinate(int, int);
    int getX();
    int getY();
    void setDirection(directions);
    directions getDirection();
};


#endif //PACMAN_COORDINATE_H
