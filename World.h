//
// Created by danik on 16.03.2018.
//
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include "Wall.h"
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
    Entity* getEntityByPos(int, int);

private:
    char **m_map;
    int m_sizeX;
    int m_sizeY;
};


#endif //CRAZYTANKS_WORLD_H
