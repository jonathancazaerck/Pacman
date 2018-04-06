//
// Created by Jonathan Cazaerck on 6/04/18.
//

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#ifndef PACMAN_JSONREADER_H
#define PACMAN_JSONREADER_H


class JsonReader {
public:
    void read();
    void showJson();
    void getCoordinates();

private:
    json j;

    void getPacmanCoordinates();
    void getGhostCoordinates();
    void getInfrastructure();
    void getBonuses();
};


#endif //PACMAN_JSONREADER_H
