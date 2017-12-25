#include "Had.h"

Had::ClanekHada::ClanekHada(
        const Souradnice &souradnice,
        Had::ClanekHada *predchoziClanek,
        Had::ClanekHada *dalsiClanek
) : souradnice(souradnice),
    dalsiClanek(dalsiClanek),
    predchoziClanek(predchoziClanek) {}

Had::Had(Souradnice pocatecniPozice) {
    this->prvniClanek = new ClanekHada(pocatecniPozice, nullptr, nullptr);
    this->posledniClanek = prvniClanek;
    this->delka = 1;
}

bool Had::pohniSe(int smer, HraciPole &hraciPole) {

    this->prvniClanek = new ClanekHada(this->prvniClanek->souradnice, nullptr, this->prvniClanek);
    this->prvniClanek->dalsiClanek->predchoziClanek = this->prvniClanek;

    switch (smer) {
        case Souradnice::SMER_DOLEVA:
            this->prvniClanek->souradnice.x--;
            break;
        case Souradnice::SMER_DOPRAVA:
            this->prvniClanek->souradnice.x++;
            break;
        case Souradnice::SMER_NAHORU:
            this->prvniClanek->souradnice.y++;
            break;
        case Souradnice::SMER_DOLU:
            this->prvniClanek->souradnice.y--;
            break;
    }

    if (*(hraciPole.jidlo) == this->prvniClanek->souradnice) {
        this->delka++;
        delete hraciPole.jidlo;
        hraciPole.jidlo = nullptr;
    } else {
        Had::ClanekHada *tmp = this->posledniClanek;

        this->posledniClanek = this->posledniClanek->predchoziClanek;
        this->posledniClanek->dalsiClanek = nullptr;

        delete tmp;
    }

    return this->nezkolidovalJsemSamSeSebou();
}

bool Had::nezkolidovalJsemSamSeSebou() {
    Had::ClanekHada *keKontrole = this->prvniClanek->dalsiClanek;
    while (keKontrole) {
        if (this->prvniClanek->souradnice == keKontrole->souradnice) {
            return false;
        }
        keKontrole = keKontrole->dalsiClanek;
    }
    return true;
}
