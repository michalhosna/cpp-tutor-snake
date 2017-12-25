#include "Souradnice.h"
#include "HraciPole.h"


#ifndef BARTIKOVA_SNAKE_HAD_H
#define BARTIKOVA_SNAKE_HAD_H


class Had {
    bool nezkolidovalJsemSamSeSebou();

public:
    class ClanekHada {

    public:
        Souradnice souradnice;
        ClanekHada *dalsiClanek, *predchoziClanek;

        ClanekHada(const Souradnice &souradnice, ClanekHada *predchoziClanek, ClanekHada *dalsiClanek);
    };

    ClanekHada *prvniClanek;
    ClanekHada *posledniClanek;
    int delka;


    bool pohniSe(int smer, HraciPole &hraciPole);

    explicit Had(Souradnice pocatecniPozice);
};


#endif //BARTIKOVA_SNAKE_HAD_H
