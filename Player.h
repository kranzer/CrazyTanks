//
// Created by danik on 17.03.2018.
//
#include "Tank.h"
#ifndef CRAZYTANKS_PLAYER_H
#define CRAZYTANKS_PLAYER_H


class Player : public Tank{
public:
    Player();
    void shoot() override;
    void setLives(int);
    int getLives();

private:
    int m_lives = 3;
};


#endif //CRAZYTANKS_PLAYER_H
