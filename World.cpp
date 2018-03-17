//
// Created by danik on 16.03.2018.
//

#include "World.h"

World::World(int size_X, int size_Y, Player *p, vector<Enemy*> enemies, vector<Wall*> walls): m_sizeX(size_X), m_sizeY(size_Y) {
    m_map = new char*[m_sizeX];
    for (int i = 0; i < m_sizeX; i++) {
        m_map[i] = new char[m_sizeY];
    }
    drawEntity(p);
    for (auto enemy: enemies){
        drawEntity(enemy);
    }
}
World::~World() {
    for (int i=0; i < m_sizeX; i++)
        delete [] m_map[i];// each array of characters

    delete [] m_map;
}

void World::drawEntity(Entity *e) {
    int _x = e->getX();
    int _y = e->getY();

    m_map[_x][_y] = e->getEntitySymbol();
}

char World::checkPos(int x, int y) {
    return m_map[x][y];
}