//
// Created by danik on 16.03.2018.
//

#include "World.h"

World::World(int size_X, int size_Y): m_sizeX(size_X), m_sizeY(size_Y) {
    m_map = new char*[m_sizeX];
    for (int i = 0; i < m_sizeX; i++) {
        m_map[i] = new char[m_sizeY];
    }
}
World::~World() {
    for (int i=0; i < m_sizeX; i++)
        delete [] m_map[i];// each array of characters

    delete [] m_map;
}