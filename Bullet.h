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
    int m_incX;
    int m_incY;
    World *m_world;
public:
    Bullet(Tank *, World *);
    bool persuadeDirection(char);
};


#endif //CRAZYTANKS_BULLET_H
