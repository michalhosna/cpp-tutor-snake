#include "Souradnice.h"

#ifndef BARTIKOVA_SNAKE_HRACIPOLE_H
#define BARTIKOVA_SNAKE_HRACIPOLE_H


class HraciPole {
public:
    int sirka, vyska;
    Souradnice *jidlo;

    HraciPole(unsigned int sirka, unsigned int vyska);

    void vygenerujJidlo();

    bool existujeJidlo();

};


#endif //BARTIKOVA_SNAKE_HRACIPOLE_H
