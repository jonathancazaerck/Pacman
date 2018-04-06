#include <iostream>
#include "Game.h"
#include "SDLFactory.h"
#include "JsonReader.h"

int main() {

      JsonReader* jsonReader = new JsonReader();
      jsonReader->read();
      jsonReader->getCoordinates();

//    AbstractFactory* abstractFactory = new SDLFactory();
//    Game* game = new Game(abstractFactory);
//    game->run();

    return 0;
}