//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H


#include "Player.h"
namespace PAC {
    class Pacman : public Player {
    public:
        Pacman(int x, int y, Game *game);

        void update();

        void onCollisionWith(Wall *wall);

        virtual void visualize() {};

        virtual void render() {};

        virtual void kill(int i);

        bool isKilled = false;

    private:
        void stopMoving();
    };

}
#endif //PACMAN_PACMAN_H
