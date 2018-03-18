//
// Created by danik on 17.03.2018.
//

#include "Player.h"

Player::Player(int x, int y) {
    setEntitySymbol('p');
    setX(x);
    setY(y);
}

void Player::setLives(int lives) {
    m_lives = lives;
}

int Player::getLives() {
    return m_lives;
}

void Player::shoot() {

}