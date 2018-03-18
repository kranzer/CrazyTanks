//
// Created by danik on 16.03.2018.
//
#include <algorithm>
#include "World.h"
#include <iostream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

World::World(int size_X, int size_Y): m_sizeX(size_X), m_sizeY(size_Y) {
    m_map = new char*[m_sizeX];
    for (int i = 0; i < m_sizeX; i++) {
        m_map[i] = new char[m_sizeY];
        for (int j = 0; j < m_sizeY; j++) {
            m_map[i][j] = ' ';
        }
    }
    m_p = new Player(8,8);
    m_walls = wallGenerator();
    m_tanks = {new Enemy(3,3), new Enemy(4,5), };
    m_tanks.push_back(m_p);
    drawEntities(m_walls);

}

vector<Wall*> World::wallGenerator() {
    vector<Wall*> walls{};
    for (int i = 0; i < m_sizeX; i++){
        auto w = new Wall(i, 0);
        walls.push_back(w);
    }

    for (int i = 0; i < m_sizeY; i++) {
        auto w = new Wall(0, i);
        walls.push_back(w);
    }

    for (int i = m_sizeY-1; i > 0; i--) {
        auto w = new Wall(m_sizeX-1, i);
        walls.push_back(w);
    }

    for (int i = m_sizeX-1; i > 0; i--) {
        auto w = new Wall(i, m_sizeY-1);
        walls.push_back(w);
    }

    return walls;
}


void World::show() {
    clearScreen();
    drawEntities(m_tanks);
    for (int i = 0; i < m_sizeY; i++){
        for (int j = 0; j < m_sizeX; j++){
            cout << m_map[i][j];
        }
        cout << endl;
    }
}

World::~World() {
    for (int i=0; i < m_sizeX; i++)
        delete [] m_map[i];
    delete [] m_map;
}

void World::drawEntities(const vector<Wall*>& walls) {
    for(auto w: walls){
        int _x = w->getX();
        int _y = w->getY();

        m_map[_y][_x] = w->getEntitySymbol();
    }
}

void World::drawEntities(const vector<Tank*>& tanks) {
    for(auto const t: tanks){
        int _x = t->getX();
        int _y = t->getY();

        m_map[_y][_x] = t->getEntitySymbol();
    }
}

void World::worldCycle() {
    int c = 0;
    while (true) {
        switch((c=getch())) {
            case KEY_UP:
				clearCell(m_p->getX(), m_p->getY());
                m_p->moveUp();
                break;
            case KEY_DOWN:
				clearCell(m_p->getX(), m_p->getY());
                m_p->moveDown();
                break;
            case KEY_LEFT:
				clearCell(m_p->getX(), m_p->getY());
                m_p->moveLeft();
                break;
            case KEY_RIGHT:
				clearCell(m_p->getX(), m_p->getY());
                m_p->moveRight();
                break;
        }

        show();
    }
}

void World::clearCell(int x, int y) {
    m_map[y][x] = ' ';
}

void World::clearScreen() {
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
void World::killTank(Tank *t) {
    vector<Tank*>::iterator toBeKilled;
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
