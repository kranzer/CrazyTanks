//
// Created by danik on 16.03.2018.
//

#ifndef CRAZYTANKS_ENTITY_H
#define CRAZYTANKS_ENTITY_H


class Entity {
public:
    Entity(int, int);
    Entity();
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    void setEntitySymbol(char);
    char getEntitySymbol();
private:
    int m_X;
    int m_Y;
    char m_symbol;

};


#endif //CRAZYTANKS_ENTITY_H
