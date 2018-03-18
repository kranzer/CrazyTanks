//
// Created by danik on 17.03.2018.
//

#include "Tank.h"

char Tank::getDirection() {
    return m_direction;
}

void Tank::moveUp() {
    setX(getX());
    setY(getY() - 1);
	m_direction = 'u';
}

void Tank::moveDown() {
    setX(getX());
    setY(getY() + 1);
	m_direction = 'd';
}

void Tank::moveRight() {
    setX(getX() + 1);
    setY(getY());
	m_direction = 'r';
}

void Tank::moveLeft() {
    setX(getX() - 1);
    setY(getY());
	m_direction = 'l';
}
