//
// Created by Jonathan Cazaerck on 6/04/18.
//

#include "JsonReader.h"

void JsonReader::read() {
    std::ifstream i("../levels/level1.json");
    i >> j;
}

void JsonReader::showJson() {
    read();
    std::cout << j << std::endl;
}

void JsonReader::getCoordinates() {
    getPacmanCoordinates();
    getGhostCoordinates();
    getInfrastructure();
}

void JsonReader::getPacmanCoordinates() {
    //json pacmanJson = j["Pacman"];

    int x = j["Pacman"].at("x").get<int>();
    int y = j["Pacman"].at("y").get<int>();

    std::cout << "Pacman coordinate: \t" << x << "\t" << y << std::endl;
}

void JsonReader::getGhostCoordinates() {
    for (auto it = j["Ghosts"].begin(); it != j["Ghosts"].end(); ++it)
    {
        std::cout << "Ghost coordinate: \t" << it.value().at("x").get<int>() << "\t" << it.value().at("y").get<int>() << "\n";
    }
}

void JsonReader::getInfrastructure() {
    for (auto it = j["Walls"].begin(); it != j["Walls"].end(); ++it)
    {
        std::string type = it.value().at("type").get<std::string>();
        std::cout << type << std::endl;

        if((type.compare("horizontal")) != 0){
            for(int i = (it.value().at("beginY").get<int>()); i <= (it.value().at("end")); i++){
                std::cout << "Wall coordinate: \t" << it.value().at("beginX").get<int>() << "\t" << i << std::endl;
            }
        }

        else{
            for(int i = (it.value().at("beginX").get<int>()); i <= (it.value().at("end")); i++){
                std::cout << "Wall coordinate: \t" << i << "\t" << it.value().at("beginY").get<int>() << std::endl;
            }
        }
    }
}

