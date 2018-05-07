//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H


#include "Player.h"
namespace PAC {
    class Wall;

    class Ghost : public Player {
    protected:
        bool enemy;
    private:
        int noEnemyLifetime;
        bool bonusGetted;
        int defaultX, defaultY;
    public:
        Ghost(int x, int y, Game *game);

        void update();

        void onCollisionWith(Wall *wall);

        //void onCollisionWith(Ghost* ghost);
        bool getEnemy();

        void setNotEnemy();

        void setBonusGetted();

        bool getBonusGetted();

        void timetick();

        virtual void visualize() {};

        virtual void render() {};

        void resetPosition();

        virtual ~Ghost();
    };
}

#endif //PACMAN_GHOST_H
