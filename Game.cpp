//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include <thread>
#include <array>
#include <string>
#include <iostream>
#include "Constants.h"
#include "Game.h"


Game::Game() {

    //Constructor
    pacman = new Pacman(10, 10);

    ghosts.push_back(new Ghost(3, 5));
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

    for (Ghost *ghost: ghosts) {
//        std::cout << ghost->getX() << '\t' << ghost->getY() << std::endl;
        grid[ghost->getX()][ghost->getY()] = "G";
    }

    for (Bullet *bullet : bullets) {
        int x = bullet->getX();
        int y = bullet->getY();
        if(!bullet->getEated()){
            grid[x][y] = "*";
        }
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

    //@todo: collision between Pacman and wall
    //@todo: collision between Pacman and ghost

    std::cout << "Tick " << ghosts.size() << std::endl;


    for (Ghost *ghost1 : ghosts) {
        for (Ghost *ghost2 : ghosts) {
//            std::cout << "collision check" << std::endl;
//        Ghost* ghost1 = ghosts[1];
//        Ghost* ghost2 = ghosts[2];

            if (ghost1->checkCollision(ghost2, false, true)) {
                ghost1->onCollisionWith(ghost2);
                ghost2->onCollisionWith(ghost1);
                std::cout << "collision" << std::endl;
            }
        }
    }

    for (Ghost *ghost : ghosts) {
        for (Wall *wall : walls) {
            if (ghost->checkCollision(wall, false, false)) {
                ghost->onCollisionWith(wall);
            }
        }
    }

    for (Bullet *bullet : bullets){
        if(bullet->checkCollision(pacman,true, false)){
            bullet->onCollisionWith(pacman);
        }
    }

    pacman->update();
    for (Ghost *ghost:ghosts)
        ghost->update();



}