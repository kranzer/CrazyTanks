//
// Created by danik on 17.03.2018.
//

#include "Tank.h"

char Tank::getDirection() {
    return m_direction;
}

void Tank::setDirection(char direction) {
    m_direction = direction;
}

void Tank::moveUp() {
    setX(getX());
    setY(getY() - 1);
}

void Tank::moveDown() {
    setX(getX());
    setY(getY() +1);
}

void Tank::moveRight() {
    setX(getX() + 1);
    setY(getY());
}

void Tank::moveLeft() {
    setX(getX() - 1);
    setY(getY());
}
