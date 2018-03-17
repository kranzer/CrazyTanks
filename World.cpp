//
// Created by danik on 16.03.2018.
//
#include <algorithm>
#include "World.h"

World::World(int size_X, int size_Y, Player *p, vector<Enemy*> enemies, vector<Wall*> walls): m_sizeX(size_X), m_sizeY(size_Y) {
    m_map = new char*[m_sizeX];
    for (int i = 0; i < m_sizeX; i++) {
        m_map[i] = new char[m_sizeY];
    }
    m_tanks.push_back(p);
    m_tanks.insert(m_tanks.end(), enemies.begin(), enemies.end());
    drawEntity(p);
    for (auto enemy: enemies){
        drawEntity(enemy);
    }
}
World::~World() {
    for (int i=0; i < m_sizeX; i++)
        delete [] m_map[i];
    delete [] m_map;
}

void World::drawEntity(Entity *e) {
    int _x = e->getX();
    int _y = e->getY();

    m_map[_x][_y] = e->getEntitySymbol();
}

void World::killTank(Tank *t) {
    std::vector<Tank*>::iterator toBeKilled;
    toBeKilled = find(m_tanks.begin(), m_tanks.end(), t);

    if (toBeKilled!=m_tanks.end())
    {
        m_map[(*toBeKilled)->getX()][(*toBeKilled)->getY()] = ' ';
        delete *toBeKilled;
        m_tanks.erase(toBeKilled);
    }
}

char World::checkPos(int x, int y) {
    return m_map[x][y];
}

Tank* World::getTankByPos(int x, int y) {
    for(vector<Tank*>::const_iterator it = m_tanks.begin(); it != m_tanks.end(); ++it){
        if((*it)->getX() == x && (*it)->getY() == y){
            return *it;
        }
    }
}