//
// Created by Jonathan Cazaerck on 16/04/18.
//

#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H


#include "Ghost.h"
namespace PAC {
    class Score {
    public:
        Score();

        void add(Ghost *);

        void add(Bullet *);

        virtual void visualize() {};

        virtual void render() {};
    protected:
        int score;
    };
}

#endif //PACMAN_SCORE_H
