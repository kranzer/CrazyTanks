//
// Created by danik on 17.03.2018.
//

#include "Game.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

Game::Game() {
    m_world = new World(20, 20);
    m_world->show();
	gameCycle();
}
void Game::playerControl() {
	int c = 0;
	while (true) {
		switch ((c = getch())) {
		case KEY_UP:
			m_world->safeMoveUp(m_world->getPlayer());
			break;
		case KEY_DOWN:
			m_world->safeMoveDown(m_world->getPlayer());
			break;
		case KEY_LEFT:
			m_world->safeMoveLeft(m_world->getPlayer());
			break;
		case KEY_RIGHT:
			m_world->safeMoveRight(m_world->getPlayer());
			break;
		case KEY_SPACE:
			Bullet *b = new Bullet(m_world->getPlayer(), m_world);
			thread shoot(&Bullet::persuadeDirection, b, 'e');
			shoot.detach();
			break;
		}
	}
}

void Game::screenControl() {
	while (true) {
		m_world->show();
		Sleep(100);
	}
}

void Game::enemyControl(Tank *t) {
	while (true) {
		m_world->safeMoveUp(t);
		Sleep(700);
		m_world->safeMoveDown(t);
		Sleep(700);
		m_world->safeMoveLeft(t);
		Sleep(700);
		m_world->safeMoveRight(t);
		m_world->show();
	}
}

void Game::gameCycle() {
	thread first(&Game::playerControl, this);
	thread second(&Game::enemyControl, this, m_world->getTanks()[0]);
	thread third(&Game::screenControl, this);
	first.join();
	second.join();
	third.join();
}