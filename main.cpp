#include <iostream>
#include "SDLGame.h"
#include "SDLFactory.h"
#include "JsonReader.h"

//int main() {
int main(int argc, char *argv[]) {


//      JsonReader* jsonReader = new JsonReader();
//      jsonReader->read();
//      jsonReader->getAllCoordinates();

    PAC::AbstractFactory *abstractFactory = new SDLPAC::SDLFactory("Jonathan Cazaerck", 200, 200, PAC::SCREEN_WIDTH, PAC::SCREEN_HEIGHT, false);
    PAC::Game *game = abstractFactory->createGame(abstractFactory);
    game->run();
    std::cout<<"Delete game"<<std::endl;
    delete game;
    std::cout<<"Delete abstractFactory"<<std::endl;
    delete abstractFactory;
   return 0;
}
