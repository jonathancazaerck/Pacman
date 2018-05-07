//
// Created by Jonathan Cazaerck on 6/04/18.
//

#include "JsonReader.h"
namespace PAC {
    void JsonReader::read() {
        std::ifstream i("../levels/level1.json");
        i >> j;
    }

    void JsonReader::showJson() {
        read();
        std::cout << j << std::endl;
    }

    void JsonReader::getAllCoordinates() {
        getPacmanCoordinates();
        getFixedNonInfrastructuralCoordinates("Ghosts");
        getInfrastructure("Bullets", bulletStep);
        getFixedNonInfrastructuralCoordinates("Bonuses");
        getInfrastructure("Walls", wallStep);
    }

    int JsonReader::getLevel() {
        return j.at("Level").get<int>();
    }

    Coordinate *JsonReader::getPacmanCoordinates() {
        int x = j["Pacman"].at("x").get<int>();
        int y = j["Pacman"].at("y").get<int>();

        //std::cout << "Pacman coordinate: \t" << x << "\t" << y << std::endl;

        return new Coordinate(x, y);
    }

    std::vector<Coordinate *> JsonReader::getFixedNonInfrastructuralCoordinates(std::string objectType) {

//    std::cout << "ObjectType: " << objectType << std::endl;

        std::vector<Coordinate *> coordinates;

        for (auto it = j[objectType].begin(); it != j[objectType].end(); ++it) {
//        std::cout << "Fixed object coordinate: \t" << it.value().at("x").get<int>() << "\t" << it.value().at("y").get<int>() << "\n";
            int x = it.value().at("x").get<int>();
            int y = it.value().at("y").get<int>();
            Coordinate *coordinate = new Coordinate(x, y);


            //Try if there is a direction given
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

    std::vector<Coordinate *> JsonReader::getInfrastructure(std::string objectType, int step) {

        std::vector<Coordinate *> coordinates;

        for (auto it = j[objectType].begin(); it != j[objectType].end(); ++it) {
            std::string type = it.value().at("type").get<std::string>();
            //std::cout << type << std::endl;

            if ((type.compare("horizontal")) != 0) {
                for (int i = (it.value().at("beginY").get<int>()); i <= (it.value().at("end")); i = i + step) {
//                std::cout << "Wall coordinate: \t" << it.value().at("beginX").get<int>() << "\t" << i << std::endl;
                    int x = it.value().at("beginX").get<int>();
                    int y = i;
                    Coordinate *coordinate = new Coordinate(x, y);
                    coordinates.push_back(coordinate);

                }
            } else {
                for (int i = (it.value().at("beginX").get<int>()); i <= (it.value().at("end")); i = i + step) {
//                std::cout << "Wall coordinate: \t" << i << "\t" << it.value().at("beginY").get<int>() << std::endl;
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
