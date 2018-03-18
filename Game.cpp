//
// Created by danik on 17.03.2018.
//

#include "Game.h"

Game::Game() {
    m_world = new World(20, 20);
    m_world->show();
    m_world->worldCycle();
}
