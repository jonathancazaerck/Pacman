//
// Created by Jonathan Cazaerck on 10/03/18.
//

#include "SDLFactory.h"
#include "SDLPacman.h"
#include "SDLWall.h"
#include "SDLGhost.h"
#include "SDLBullet.h"
#include "SDLBonus.h"
#include "SDLScore.h"
#include "SDLGame.h"


SDLFactory::SDLFactory(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
    sdlInitiator = new SDLInitiator();
    if(!sdlInitiator->init(title,xPos,yPos,width,height,fullscreen)){
        std::cout<<"Can't initialize SDL";
        exit(1);
    }
}

//Create game objects
Pacman* SDLFactory::createPacman(int x, int y, Game* game) {
    return new SDLPacman(x, y, game, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
}

Wall* SDLFactory::createWall(int x, int y) {
    return new SDLWall(x, y, sdlInitiator->getWallTexture(), sdlInitiator->getRenderer());
}

Ghost* SDLFactory::createGhost(int x, int y, Game* game) {
    return new SDLGhost(x, y, game, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
}

Bullet* SDLFactory::createBullet(int x, int y) {
    return new SDLBullet(x, y, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
}

Bonus* SDLFactory::createBonus(int x, int y) {
    return new SDLBonus(x, y, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
}

Score* SDLFactory::createScore() {
    return new SDLScore(sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
}

Game* SDLFactory::createGame(AbstractFactory* abstractFactory) {
    game = new SDLGame(abstractFactory,sdlInitiator->getRenderer(),sdlInitiator->getWindow());
    return game;
}

