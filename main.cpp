#include <iostream>
#include "Game.h"
#include "SDLFactory.h"

int main() {

    AbstractFactory* abstractFactory = new SDLFactory();
    Game* game = new Game(abstractFactory);
    game->run();

    return 0;
}