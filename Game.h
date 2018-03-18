//
// Created by danik on 17.03.2018.
//
#include "World.h"
#include "Wall.h"
#include "Bullet.h"
#include "Enemy.h"
#include <conio.h>
#include <thread>

#ifndef CRAZYTANKS_GAME_H
#define CRAZYTANKS_GAME_H


class Game {
public:
    Game();
	void playerControl();
	void screenControl();
	void enemyControl(Tank *t);
	void gameCycle();
private:
    World *m_world;
    int count;
    int status;
    //time
    int lives;
};


#endif //CRAZYTANKS_GAME_H
