//
// Created by Jonathan Cazaerck on 6/04/18.
//

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "Game.h"
#include "Coordinate.h"
#include "Constants.h"

using json = nlohmann::json;

#ifndef PACMAN_JSONREADER_H
#define PACMAN_JSONREADER_H


class JsonReader {
public:
    Game* game;
    void read();
    void showJson();
    void getAllCoordinates();
    int getLevel();
    Coordinate * getPacmanCoordinates();
    std::vector<Coordinate *> getFixedNonInfrastructuralCoordinates(std::string objectType);
    std::vector<Coordinate *> getInfrastructure(std::string objectType, int step);

private:
    json j;
};


#endif //PACMAN_JSONREADER_H
