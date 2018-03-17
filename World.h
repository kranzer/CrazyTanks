//
// Created by danik on 16.03.2018.
//
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include "Wall.h"
#include "Tank.h"
#include <vector>
using namespace std;
#ifndef CRAZYTANKS_WORLD_H
#define CRAZYTANKS_WORLD_H


class World {
public:
    World(int, int, Player*, vector<Enemy*>, vector<Wall*>);
    ~World();
    void drawEntity(Entity*);
    char checkPos(int, int);
    Tank* getTankByPos(int, int);
    void killTank(Tank*);

private:
    char **m_map;
    int m_sizeX;
    int m_sizeY;
    vector<Tank*> m_tanks;
};


#endif //CRAZYTANKS_WORLD_H
