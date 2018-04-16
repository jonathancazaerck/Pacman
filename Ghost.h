//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H


#include "Player.h"

class Wall;

class Ghost : public Player{
protected:
    bool enemy;
private:
    int noEnemyLifetime;
    bool bonusGetted;
public:
    Ghost(int x, int y, Game* game);
    void update();
    void onCollisionWith(Wall* wall);
    //void onCollisionWith(Ghost* ghost);
    bool getEnemy();
    void setNotEnemy();
    void setBonusGetted();
    bool getBonusGetted();
    void timetick();
    virtual void visualize(){};
    virtual void render(){};
};


#endif //PACMAN_GHOST_H
