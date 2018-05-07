//
// Created by Jonathan Cazaerck on 12/03/18.
//

#ifndef PACMAN_BONUS_H
#define PACMAN_BONUS_H


#include "Bullet.h"
namespace PAC {
    class Bonus : public Bullet {
    private:
        bool active;
    public:
        Bonus(int x, int y);

        void onCollisionWith(Pacman *pacman);

        bool isActive() const;

        bool isActive();

        void setDeactive();

        virtual void visualize() {};

        virtual void render() {};
    };
}


#endif //PACMAN_BONUS_H
