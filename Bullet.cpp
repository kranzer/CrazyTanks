//
// Created by danik on 17.03.2018.
//

#include "Bullet.h"

Bullet::Bullet(Tank *t, World *w) : m_world(w) {
    switch (t->getDirection()){
        case 'u':
            this->setX(t->getX());
            this->setY(t->getY() - 1);
            m_incY = -1;
            m_incX = 0;
        case 'd':
            this->setX(t->getX());
            this->setY(t->getY() + 1);
            m_incY = 1;
            m_incX = 0;
        case 'r':
            this->setX(t->getX() + 1);
            this->setY(t->getY());
            m_incY = 0;
            m_incX = 1;
        case 'l':
            this->setX(t->getX() - 1);
            this->setY(t->getY());
            m_incY = 0;
            m_incX = -1;
    }
}

bool Bullet::persuadeDirection(char aim) {
    while (true) {
        char entity = m_world->checkPos(this->getX()+m_incX, this->getY()+m_incY);
        if(entity == aim){
            m_world->getTankByPos(this->getX(),this->getY());
            return true;
        } else if(entity == 'w') {
            return false;
        }
        else {
            this->setX(this->getX() + m_incX);
            this->setY(this->getY() + m_incY);
        }
    }
}