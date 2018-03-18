//
// Created by danik on 17.03.2018.
//
#include "Entity.h"

#ifndef CRAZYTANKS_TANK_H
#define CRAZYTANKS_TANK_H


class Tank : public Entity {
public:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    char getDirection();
private:
    char m_direction = 'u';
};


#endif //CRAZYTANKS_TANK_H
