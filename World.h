//
// Created by danik on 16.03.2018.
//

#ifndef CRAZYTANKS_WORLD_H
#define CRAZYTANKS_WORLD_H


class World {
public:
    World(int, int);
    ~World();

private:
    char **m_map;
    int m_sizeX;
    int m_sizeY;
};


#endif //CRAZYTANKS_WORLD_H
