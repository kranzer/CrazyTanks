//
// Created by danik on 17.03.2018.
//
#include "Tank.h"
#ifndef CRAZYTANKS_ENEMY_H
#define CRAZYTANKS_ENEMY_H


class Enemy : public Tank{
public:
    Enemy();
    void shoot() override;
private:

};


#endif //CRAZYTANKS_ENEMY_H
