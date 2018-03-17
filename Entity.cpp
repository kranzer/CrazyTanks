//
// Created by danik on 16.03.2018.
//

#include "Entity.h"

Entity::Entity(int x, int y, int length, int height): m_X(x), m_Y(y), m_length(length), m_height(height) {

}

Entity::Entity() {
    m_X = 0;
    m_Y = 0;
    m_height = 1;
    m_length = 1;
}

