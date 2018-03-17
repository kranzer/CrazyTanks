//
// Created by danik on 16.03.2018.
//

#ifndef CRAZYTANKS_ENTITY_H
#define CRAZYTANKS_ENTITY_H


class Entity {
public:
    Entity(int, int, int, int);
    Entity();
private:
    int m_X;
    int m_Y;
    int m_length;
    int m_height;

};


#endif //CRAZYTANKS_ENTITY_H
