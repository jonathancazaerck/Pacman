#include <iostream>
#include "SDLGame.h"
#include "SDLFactory.h"
#include "JsonReader.h"

int main(int argc, char *argv[]) {

	//Create new SDLFactory
    PAC::AbstractFactory *abstractFactory = new SDLPAC::SDLFactory(PAC::windowTitle, PAC::windowXPos, PAC::windowYPos, PAC::SCREEN_WIDTH, PAC::SCREEN_HEIGHT, false);

    //Create game, run game and delete it
    PAC::Game *game = abstractFactory->createGame(abstractFactory);
    game->run();
    std::cout<<"Delete game"<<std::endl;
    delete game;

    //Delete factory
    std::cout<<"Delete abstractFactory"<<std::endl;
    delete abstractFactory;
   return 0;
}
