//
// Created by Jonathan Cazaerck on 16/04/18.
//

#include "Score.h"


Score::Score() {
    score = 0;
}

void Score::add(Ghost*) {
    score = score+10;
}

void Score::add(Bullet*) {
    score = score + 1;
}