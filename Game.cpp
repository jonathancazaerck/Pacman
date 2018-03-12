//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <thread>
#include <array>
#include <string>
#include <iostream>
#include "Constants.h"
#include "Game.h"
#include "Bonus.h"


Game::Game() {

    //Constructor
    pacman = new Pacman(20, 10);

    bonuses.push_back(new Bonus(15, 10));

    ghosts.push_back(new Ghost(1, 1));
    ghosts.push_back(new Ghost(4, 8));
    ghosts.push_back(new Ghost(7, 8));
    ghosts[1]->moveRight();

    bullets.push_back(new Bullet(9,10));
    bullets.push_back(new Bullet(8,10));
    bullets.push_back(new Bullet(7,10));

    //Upper and bottom border
    for (int i = 0; i <= maxX; i++) {
        walls.push_back(new Wall(i, maxY));
        walls.push_back(new Wall(i, minY));
    }

    //left right border and no overlap with above
    for (int i = 1; i <= maxY - 1; i++) {
        walls.push_back(new Wall(minX, i));
        walls.push_back(new Wall(maxX, i));
    }


}

void Game::run() {
    while (true) {
        std::cout << std::string(10, '\n');
        print();
        tick();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Game::print() {
    std::array<std::array<std::string, maxY + 1>, maxX + 1> grid;

    for (Wall *wall : walls) {
        int x = wall->getX();
        int y = wall->getY();
        grid[x][y] = "+";
    }

    for (Bullet *bullet : bullets) {
        int x = bullet->getX();
        int y = bullet->getY();
        if(!bullet->getEated()){
            grid[x][y] = "*";
        }
    }

    for (Bonus *bonus : bonuses) {
        int x = bonus->getX();
        int y = bonus->getY();
        if(!bonus->getEated()){
            grid[x][y] = "B";
        }
    }

    for (Ghost *ghost: ghosts) {
//        std::cout << ghost->getX() << '\t' << ghost->getY() << std::endl;
        grid[ghost->getX()][ghost->getY()] = "G";
    }

    grid[pacman->getX()][pacman->getY()] = "P";

    for (int y = 0; y <= maxY; y++) {
        for (int x = 0; x <= maxX; x++) {
            std::string str = grid[x][y];
            if (str.empty()) {
                std::cout << " ";
            } else {
                std::cout << str;
            }
        }
        std::cout << std::endl;
    }
}

void Game::tick() {
    std::cout << "Tick " << std::endl;

//DELETED: COLLISION BETWEEN TWO GHOSTS = NOT NECESSARY
//    for (Ghost *ghost1 : ghosts) {
//        for (Ghost *ghost2 : ghosts) {
////            std::cout << "collision check" << std::endl;
////        Ghost* ghost1 = ghosts[1];
////        Ghost* ghost2 = ghosts[2];
//
//            if (ghost1->checkCollision(ghost2, false, true)) {
//                ghost1->onCollisionWith(ghost2);
//                ghost2->onCollisionWith(ghost1);
//                //std::cout << "collision" << std::endl;
//            }
//        }
//    }

    for (Ghost *ghost : ghosts) {
        for (Wall *wall : walls) {
            if (ghost->checkCollision(wall, false, false, ghost->getDirection())) {
                ghost->onCollisionWith(wall);
            }
        }
    }

    for (Bullet *bullet : bullets){
        if(bullet->checkCollision(pacman,true, false, stop)){
            bullet->onCollisionWith(pacman);
        }
    }

    for (Wall *wall : walls){
        if(pacman->checkCollision(wall, false, false, stop)){
            pacman->onCollisionWith(wall);
        }
    }

    for(Bonus *bonus : bonuses){
        bonus->setDeactive();
        if(bonus->checkCollision(pacman,true, false, stop)){
            bonus->onCollisionWith(pacman);
        }
    }

    //Check if there're some bonuses and if so -> transform all the ghosts.
    for(Bonus *bonus : bonuses) {
        if (bonus->isActive()) {
            for (Ghost *ghost : ghosts) {
                ghost->setNotEnemy();
            }
        }
    }


    for (Ghost *ghost : ghosts){
        if(pacman->checkCollision(ghost,true,true, stop)){
            if(ghost->getEnemy()){
                //als de ghost de vijand is
                std::cout << "DOOD!!!!" << std::endl;
                exit(0); //@fixme: maak dit wat eleganter
            }

            else{
                //ghost is de vijand niet
                std::cout << "BONUS" << std::endl;
            }
        }
    }

    pacman->update();
    for (Ghost *ghost:ghosts)
        ghost->update();



}