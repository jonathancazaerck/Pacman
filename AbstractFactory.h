//
// Created by Jonathan Cazaerck on 10/03/18.
//

#ifndef PACMAN_ABSTRACTFACTORY_H
#define PACMAN_ABSTRACTFACTORY_H


class AbstractFactory {
public:
    virtual bool init()=0;
    virtual bool loadMedia()=0;
    virtual void close()=0;
    virtual bool pollEvent()=0;
};


#endif //PACMAN_ABSTRACTFACTORY_H
