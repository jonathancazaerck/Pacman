//
// Created by Jonathan Cazaerck on 6/04/18.
//
// LIBRARY OF NLOHMANN USED HERE
// https://github.com/nlohmann

#include "JsonReader.h"
namespace PAC {
	//Read JSON-file
    void JsonReader::read() {
        std::ifstream i("levels/level1.json");
        i >> j;
    }

    //Show JSON-file in console
    void JsonReader::showJson() {
        read();
        std::cout << j << std::endl;
    }

    //Get all the coordinates of all entities from JSON-file
    void JsonReader::getAllCoordinates() {
        getPacmanCoordinates();
        getFixedNonInfrastructuralCoordinates("Ghosts");
        getInfrastructure("Bullets", bulletStep);
        getFixedNonInfrastructuralCoordinates("Bonuses");
        getInfrastructure("Walls", wallStep);
    }

    //Get level no. from json file
    int JsonReader::getLevel() {
        return j.at("Level").get<int>();
    }

    //Get coordinates from pacman from json file
    Coordinate *JsonReader::getPacmanCoordinates() {
        int x = j["Pacman"].at("x").get<int>();
        int y = j["Pacman"].at("y").get<int>();
        return new Coordinate(x, y);
    }

    //Get coordinates from the JSON-file from entities that are not walls
    //Which entity exactly will be written in the parameter when invoking this method
    std::vector<Coordinate *> JsonReader::getFixedNonInfrastructuralCoordinates(std::string objectType) {
        std::vector<Coordinate *> coordinates;

        for (auto it = j[objectType].begin(); it != j[objectType].end(); ++it) {
            int x = it.value().at("x").get<int>();
            int y = it.value().at("y").get<int>();
            Coordinate *coordinate = new Coordinate(x, y);


            //Try if there is a direction given
            //This is done for the ghosts
            try {
                std::string strDirection = it.value().at("direction").get<std::string>();

                if ((strDirection.compare("up")) == 0)
                    coordinate->setDirection(up);

                else if ((strDirection.compare("down")) == 0)
                    coordinate->setDirection(down);

                else if ((strDirection.compare("left")) == 0)
                    coordinate->setDirection(left);

                else
                    coordinate->setDirection(right);

            }
            catch (json::exception &e) {
                //do nothing, there isn't any direction given!
            }


            coordinates.push_back(coordinate);
        }

        return coordinates;
    }

    //From the JSON-file get the coordinates from all the walls
    std::vector<Coordinate *> JsonReader::getInfrastructure(std::string objectType, int step) {

        std::vector<Coordinate *> coordinates;

        for (auto it = j[objectType].begin(); it != j[objectType].end(); ++it) {
            std::string type = it.value().at("type").get<std::string>();

            if ((type.compare("horizontal")) != 0) {
                for (int i = (it.value().at("beginY").get<int>()); i <= (it.value().at("end")); i = i + step) {
                    int x = it.value().at("beginX").get<int>();
                    int y = i;
                    Coordinate *coordinate = new Coordinate(x, y);
                    coordinates.push_back(coordinate);

                }
            } else {
                for (int i = (it.value().at("beginX").get<int>()); i <= (it.value().at("end")); i = i + step) {
                    int x = i;
                    int y = it.value().at("beginY").get<int>();
                    Coordinate *coordinate = new Coordinate(x, y);
                    coordinates.push_back(coordinate);
                }
            }
        }

        return coordinates;
    }
}
