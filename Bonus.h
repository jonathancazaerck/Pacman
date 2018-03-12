//
// Created by Jonathan Cazaerck on 12/03/18.
//

#ifndef PACMAN_BONUS_H
#define PACMAN_BONUS_H


#include "Bullet.h"

class Bonus : public Bullet{
public:
    Bonus(int x, int y);
    void onCollisionWith(Pacman *pacman);

private:
    bool active;
public:
    bool isActive() const;

    bool isActive();

    void setDeactive();
};


#endif //PACMAN_BONUS_H
