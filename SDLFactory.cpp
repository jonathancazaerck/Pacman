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

namespace SDLPAC {
    SDLFactory::SDLFactory(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
        sdlInitiator = new SDLInitiator();
        if (!sdlInitiator->init(title, xPos, yPos, width, height, fullscreen)) {
            std::cout << "Can't initialize SDL";
            exit(1);
        }
    }

//Create game objects
    PAC::Pacman *SDLFactory::createPacman(int x, int y, PAC::Game *game) {
        return new SDLPacman(x, y, game, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
    }

    PAC::Wall *SDLFactory::createWall(int x, int y) {
        return new SDLWall(x, y, sdlInitiator->getWallTexture(), sdlInitiator->getRenderer());
    }

    PAC::Ghost *SDLFactory::createGhost(int x, int y, PAC::Game *game) {
        return new SDLGhost(x, y, game, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
    }

    PAC::Bullet *SDLFactory::createBullet(int x, int y) {
        return new SDLBullet(x, y, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
    }

    PAC::Bonus *SDLFactory::createBonus(int x, int y) {
        return new SDLBonus(x, y, sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
    }

    PAC::Score *SDLFactory::createScore() {
        return new SDLScore(sdlInitiator->getObjTexture(), sdlInitiator->getRenderer());
    }

    PAC::Game *SDLFactory::createGame(PAC::AbstractFactory *abstractFactory) {
        game = new SDLGame(abstractFactory, sdlInitiator->getRenderer(), sdlInitiator->getWindow());
        return game;
    }

    SDLFactory::~SDLFactory() {
        std::cout << "Delete sdlfactory:sdlinitiator" << std::endl;
        delete sdlInitiator;
    }
}

