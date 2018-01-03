//
// Created by Michal Hosna on 03/01/2018.
//

#ifndef BARTIKOVA_SNAKE_CAS_H
#define BARTIKOVA_SNAKE_CAS_H


#include <chrono>

using namespace std::chrono;

class Cas {
public:
    high_resolution_clock::time_point casResetu;

    static void pockej(unsigned int msekund);

    void vyresetujPocitadlo();

    bool uzUplynuloMilisekund(unsigned int msekund);

    Cas();
};


#endif //BARTIKOVA_SNAKE_CAS_H
