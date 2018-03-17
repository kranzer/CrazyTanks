//
// Created by danik on 17.03.2018.
//
#include "Entity.h"
#ifndef CRAZYTANKS_TANK_H
#define CRAZYTANKS_TANK_H


class Tank : public Entity {
public:
    Tank(){};
    virtual void shoot() = 0;
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    char getDirection();
private:
    char m_direction;

};


#endif //CRAZYTANKS_TANK_H
