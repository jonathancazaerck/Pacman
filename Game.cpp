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
#include "JsonReader.h"
namespace PAC {

    Game::Game(AbstractFactory *abstractFactory) {

        //Constructor
        this->abstractFactory = abstractFactory;

//    pacman = new Pacman(50, 50, this);
//    pacman->moveRight();
//
//    bonuses.push_back(new Bonus(15, 10));
//
//    ghosts.push_back(new Ghost(1, 1, this));
//    ghosts.push_back(new Ghost(4, 8, this));
//    ghosts.push_back(new Ghost(70, 50, this));
//    ghosts[0]->moveRight();
//    ghosts[2]->moveRight();
//
//    bullets.push_back(new Bullet(9,10));
//    bullets.push_back(new Bullet(8,10));
//    bullets.push_back(new Bullet(7,10));
//
//    //Upper and bottom border
//    for (int i = 0; i <= maxX; i++) {
//        walls.push_back(new Wall(i, maxY));
//        walls.push_back(new Wall(i, minY));
//    }
//
//    //left right border and no overlap with above
//    for (int i = 1; i <= maxY - 1; i++) {
//        walls.push_back(new Wall(minX, i));
//        walls.push_back(new Wall(maxX, i));
//    }
    }

//// VANAF HIER JSON

    void Game::initObjects() {

        score = abstractFactory->createScore();

        JsonReader *jsonReader = new JsonReader();
        jsonReader->read(); //read file!

        //Display level
        //std::cout << "Level id: " << jsonReader->getLevel() << std::endl;

        //Pacman
        Coordinate *coordinatePacman = jsonReader->getPacmanCoordinates();
        pacman = abstractFactory->createPacman(coordinatePacman->getX(), coordinatePacman->getY(), this);
        killInt = 0;

        //Walls
        std::vector<Coordinate *> coordinateWalls = jsonReader->getInfrastructure("Walls", wallStep);
        for (Coordinate *coordinateWall : coordinateWalls) {
            walls.push_back(abstractFactory->createWall(coordinateWall->getX(), coordinateWall->getY()));
        }

        //Ghosts
        std::vector<Coordinate *> coordinateGhosts = jsonReader->getFixedNonInfrastructuralCoordinates("Ghosts");
        for (Coordinate *coordinateGhost : coordinateGhosts) {
            Ghost *newGhost = abstractFactory->createGhost(coordinateGhost->getX(), coordinateGhost->getY(), this);
            ghosts.push_back(newGhost);
            switch (coordinateGhost->getDirection()) {
                case up:
                    newGhost->moveUp();
                    break;
                case down:
                    newGhost->moveDown();
                    break;
                case left:
                    newGhost->moveLeft();
                    break;
                case right:
                    newGhost->moveRight();
                    break;
                default:
                    //go left
                    newGhost->moveLeft();
                    break;
            }
        }

        //Bullets
        std::vector<Coordinate *> coordinateBullets = jsonReader->getInfrastructure("Bullets", bulletStep);
        for (Coordinate *coordinateBullet : coordinateBullets) {
            bullets.push_back(abstractFactory->createBullet(coordinateBullet->getX(), coordinateBullet->getY()));
            //std::cout << coordinateBullet->getX();
        }

        //Bonuses
        std::vector<Coordinate *> coordinateBonuses = jsonReader->getFixedNonInfrastructuralCoordinates("Bonuses");
        for (Coordinate *coordinateBonus : coordinateBonuses) {
            bonuses.push_back(abstractFactory->createBonus(coordinateBonus->getX(), coordinateBonus->getY()));
        }


    }


    void Game::run() {

////HIER SDL

        initObjects();
        initKeyboardController(pacman);

        for (Wall *wall:walls) {
            wall->visualize();
            wall->render();
        }

        while (getIsRunning()) {
            frameStart = getTimestamp();

            gameloop();

            frameTime = getTimestamp() - frameStart;

            if (!pacman->isKilled)
                handleEvents();

            if (frameDelay > frameTime)
                delay(frameDelay - frameTime);
        }


        showDialog("Game Over!", "You loose!");

        clean();

    }

    void Game::gameloop() {

        if (!pacman->isKilled)
            tick();

        renderClear();

        for (Bullet *bullet:bullets) {
            bullet->visualize();
            bullet->render();
        }

        for (Bonus *bonus:bonuses) {
            bonus->visualize();
            bonus->render();
        }

        score->visualize();
        score->render();

        if (!pacman->isKilled) {
            pacman->update();
            pacman->visualize();
        } else {
            if (killInt < 17) {
                pacman->kill(killInt);
                killInt++;
            } else {
                stopAll();
            }
        }

        pacman->render();

        for (Ghost *ghost:ghosts) {
            ghost->update();
            ghost->visualize();
            ghost->render();
        }

        for (Wall *wall:walls) {
            wall->render();
        }

        renderPresent();

    }

////HIER TEXT MODE
//    while (true) {
//        std::cout << std::string(10, '\n');
//        print();
//        tick();
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//}

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
            grid[x][y] = "*";
        }

        for (Bonus *bonus : bonuses) {
            int x = bonus->getX();
            int y = bonus->getY();
            grid[x][y] = "B";
        }

        for (Ghost *ghost: ghosts) {
            std::cout << ghost->getX() << '\t' << ghost->getY() << std::endl;
            grid[ghost->getX() + 1][ghost->getY() + 1] = "G";
        }

        if (pacman->getX() >= minX && pacman->getX() <= maxX
            && pacman->getY() >= minY && pacman->getY() <= maxY) {
            grid[pacman->getX() + 1][pacman->getY() + 1] = "P";
        } else {
            std::cout << "Pacman out of range" << std::endl;
        }

        for (int y = 0; y <= maxY; y++) {
            std::cout << y << "\t";
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
//    std::cout << "Tick " << std::endl;

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
                    // stop on first collision  to prevent changing directions multiple times
                    break;
                }
            }
        }

        //VECTOR TO DELETE BULLETS
        std::vector<Bullet *> toDeleteBullets;

        for (Bullet *bullet : bullets) {
            if (bullet->checkCollision(pacman, true, false, stop)) {
                score->add(bullet);
                bullet->onCollisionWith(pacman);
                toDeleteBullets.push_back(bullet);
            }
        }

        for (auto item:toDeleteBullets) {
            bullets.erase(std::remove(bullets.begin(), bullets.end(), item), bullets.end());
            delete item;
        }

        toDeleteBullets.clear();


        for (Wall *wall : walls) {
            if (pacman->checkCollision(wall, false, false, stop)) {
                pacman->onCollisionWith(wall);
            }
        }

        //VECTOR TO DELETE BULLETS
        std::vector<Bonus *> toDeleteBonuses;

        for (Bonus *bonus : bonuses) {
            bonus->setDeactive();
            if (bonus->checkCollision(pacman, true, false, stop)) {
                bonus->onCollisionWith(pacman);
                toDeleteBonuses.push_back(bonus);
            }
        }

        //Check if there're some bonuses and if so -> transform all the ghosts.
        for (Bonus *bonus : bonuses) {
            if (bonus->isActive()) {
                for (Ghost *ghost : ghosts) {
                    ghost->setNotEnemy();
                }
            }
        }

        for (auto item:toDeleteBonuses) {
            bonuses.erase(std::remove(bonuses.begin(), bonuses.end(), item), bonuses.end());
            delete item;
        }
        toDeleteBullets.clear();

        for (Ghost *ghost : ghosts) {
            if (pacman->checkCollision(ghost, true, true, stop)) {
                if (ghost->getEnemy()) {
                    //als de ghost de vijand is
                    std::cout << "DOOD!!!!" << std::endl;
                    pacman->isKilled = true;
                } else {
                    //ghost is de vijand niet
                    //std::cout << "BONUS" << std::endl;
                    if (!ghost->getBonusGetted()) {
                        score->add(ghost);
                        ghost->setBonusGetted();
                        ghost->resetPosition();
                    }
                }
            }
        }

        pacman->update();
        for (Ghost *ghost:ghosts)
            ghost->update();


    }

    bool Game::checkOccupiedByWall(Player *player, directions newDirection) const {

        for (Wall *wall : walls) {
            if (player->checkCollision(wall, false, false, newDirection)) {
                return true;
            }
        }

        return false;
    }

    Game::~Game() {
        std::cout << "Delete game:pacman" << std::endl;
        delete pacman;
        std::cout << "Delete game:ghosts" << std::endl;
        for (auto p : ghosts)
            delete p;
        std::cout << "Delete game:bullets" << std::endl;
        for (auto p : bullets)
            delete p;
        std::cout << "Delete game:walls" << std::endl;
        for (auto p : walls)
            delete p;
        std::cout << "Delete game:bonuses" << std::endl;
        for (auto p : bonuses)
            delete p;
        std::cout << "Delete game:score" << std::endl;
        delete score;
    }
}