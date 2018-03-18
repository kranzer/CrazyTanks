//
// Created by danik on 16.03.2018.
//
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include "Wall.h"
#include "Tank.h"
#include <windows.h>
#include <vector>
using namespace std;
#ifndef CRAZYTANKS_WORLD_H
#define CRAZYTANKS_WORLD_H


class World {
public:
    World(int, int);
    ~World();
    void drawEntities(const vector<Wall*>&);
    void drawEntities(const vector<Tank*>&);
    void worldCycle();
    vector<Wall*> wallGenerator();
    void show();
    char checkPos(int, int);
    Tank* getTankByPos(int, int);
    void clearScreen();
	void clearCell(int, int);
    void killTank(Tank*);

private:
    char **m_map;
    int m_sizeX;
    int m_sizeY;
    Player *m_p;
    vector<Wall*> m_walls;
    vector<Tank*> m_tanks;
};


#endif //CRAZYTANKS_WORLD_H
