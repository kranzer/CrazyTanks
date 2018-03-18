//
// Created by danik on 17.03.2018.
//

#include "Entity.h"
#include "Tank.h"
#include "World.h"

#ifndef CRAZYTANKS_BULLET_H
#define CRAZYTANKS_BULLET_H

class Bullet : public Entity{
private:
    const int velocity = 3;
    int m_incX = 0;
    int m_incY = 0;
    World *m_world;
public:
    Bullet(Tank *, World *);
	~Bullet();
    bool persuadeDirection(char);
};


#endif //CRAZYTANKS_BULLET_H
