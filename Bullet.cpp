//
// Created by danik on 17.03.2018.
//

#include "Bullet.h"

Bullet::Bullet(Tank *t, World *w) : m_world(w) {
	setEntitySymbol('b');
    switch (t->getDirection()){
        case 'u':
            setX(t->getX());
            setY(t->getY() - 1);
            m_incY = -1;
            m_incX = 0;
            break;
        case 'd':
            setX(t->getX());
            setY(t->getY() + 1);
            m_incY = 1;
            m_incX = 0;
            break;
        case 'r':
            setX(t->getX() + 1);
            setY(t->getY());
            m_incY = 0;
            m_incX = 1;
            break;
        case 'l':
            setX(t->getX() - 1);
            setY(t->getY());
            m_incY = 0;
            m_incX = -1;
            break;
        default:
            break;
    }
	m_world->drawEntity(this);
}

Bullet::~Bullet() {
	m_world->clearCell(getX(), getY());
}

bool Bullet::persuadeDirection(char aim) {
    while (true) {
        char entity = m_world->checkPos(getX()+m_incX, getY()+m_incY);
		m_world->drawEntity(this);
		Sleep(500);
        if(entity == aim){
            m_world->killTank(m_world->getTankByPos(getX()+m_incX,getY()+m_incY));
			delete this;
			return true;
        } else if(entity == 'w') {
			delete this;
			return false;
        }
        else {
			m_world->clearCell(getX(), getY());
            setX(getX() + m_incX);
            setY(getY() + m_incY);
			
        }
    }
}