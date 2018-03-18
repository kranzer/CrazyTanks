//
// Created by danik on 17.03.2018.
//
#include "World.h"
#include "Wall.h"
#include "Enemy.h"
#ifndef CRAZYTANKS_GAME_H
#define CRAZYTANKS_GAME_H


class Game {
public:
    Game();
private:
    World *m_world;
    int count;
    int status;
    //time
    int lives;
};


#endif //CRAZYTANKS_GAME_H
