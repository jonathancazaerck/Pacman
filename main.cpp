#include <iostream>
#include "SDLGame.h"
#include "SDLFactory.h"
#include "JsonReader.h"

int main() {

//      JsonReader* jsonReader = new JsonReader();
//      jsonReader->read();
//      jsonReader->getAllCoordinates();

    AbstractFactory *abstractFactory = new SDLFactory("Jonathan Cazaerck", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    Game *game = abstractFactory->createGame(abstractFactory);
    game->run();

   return 0;
}