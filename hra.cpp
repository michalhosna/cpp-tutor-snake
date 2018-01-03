
#include <cstdio>
#include <cstdlib>
#include "hra.h"
#include <iostream>
#include "console.h"
#include <vector>
#include "cas.h"


using namespace std;


char nactiVstup() {
    static char posledniSmer = Souradnice::SMER_NAHORU;
    if (jeCoCistNaVstupu()) {
        char klavesa = prectiVstup();
        switch (klavesa) {
            case 'w':
                posledniSmer = Souradnice::SMER_NAHORU;
                break;
            case 'a':
                posledniSmer = Souradnice::SMER_DOLEVA;
                break;
            case 's':
                posledniSmer = Souradnice::SMER_DOLU;
                break;
            case 'd':
                posledniSmer = Souradnice::SMER_DOPRAVA;
                break;
            default:
                break;
        }
    }

    return posledniSmer;

}

bool narazilDoSteny(Had had, HraciPole hraciPole) {
    return (
            had.prvniClanek->souradnice.x < 0 ||
            had.prvniClanek->souradnice.y < 0 ||
            had.prvniClanek->souradnice.x >= hraciPole.sirka ||
            had.prvniClanek->souradnice.y >= hraciPole.vyska
    );
}

bool jidloNeniTamCoJeHad(Had &had, HraciPole &hraciPole) {
    Had::ClanekHada *keKontrole = had.prvniClanek;
    while (keKontrole) {
        if (*(hraciPole.jidlo) == keKontrole->souradnice) {
            return false;
        }
        keKontrole = keKontrole->dalsiClanek;
    }
    return true;
}


void prepoctiSouradniceAVytiskni(char symbol, int x, int y, HraciPole &hraciPole) {
    vytiskniSymbolNaSouradnice(symbol, x + OFFSET_POCATKU_X, hraciPole.vyska + OFFSET_POCATKU_Y - y);
}


void vykresliPole(HraciPole &hraciPole) {
    for (int i = -1; i <= hraciPole.sirka; ++i) {
        prepoctiSouradniceAVytiskni(ZNAK_HRANICE, i, hraciPole.vyska, hraciPole);
        prepoctiSouradniceAVytiskni(ZNAK_HRANICE, i, -1, hraciPole);
    }

    for (int i = 0; i < hraciPole.vyska; ++i) {
        prepoctiSouradniceAVytiskni(ZNAK_HRANICE, -1, i, hraciPole);
        prepoctiSouradniceAVytiskni(ZNAK_HRANICE, hraciPole.sirka, i, hraciPole);
    }

    prepoctiSouradniceAVytiskni(ZNAK_JIDLO, hraciPole.jidlo->x, hraciPole.jidlo->y, hraciPole);

}

void vykresliHada(Had &had, HraciPole &hraciPole) {
    Had::ClanekHada *clanek = had.prvniClanek;

    prepoctiSouradniceAVytiskni(ZNAK_HAD_HLAVA, clanek->souradnice.x, clanek->souradnice.y, hraciPole);
    clanek = clanek->dalsiClanek;

    while (clanek) {
        prepoctiSouradniceAVytiskni(ZNAK_HAD, clanek->souradnice.x, clanek->souradnice.y, hraciPole);
        clanek = clanek->dalsiClanek;
    }
}

void vykresliHru(Had &had, HraciPole &hraciPole) {
    vymazObrazovku();
    vykresliPole(hraciPole);
    vykresliHada(had, hraciPole);
}

void gameOver(HraciPole &hraciPole) {
    vymazObrazovku();

    prepoctiSouradniceAVytiskni('#', hraciPole.sirka / 2 - 7, hraciPole.vyska / 2 + 2, hraciPole);
    cout << "##############";
    prepoctiSouradniceAVytiskni('#', hraciPole.sirka / 2 - 7, hraciPole.vyska / 2 + 1, hraciPole);
    cout << "             #";

    prepoctiSouradniceAVytiskni('#', hraciPole.sirka / 2 - 7, hraciPole.vyska / 2, hraciPole);
    cout << "  GAME OVER  #" << endl;

    prepoctiSouradniceAVytiskni('#', hraciPole.sirka / 2 - 7, hraciPole.vyska / 2 - 1, hraciPole);
    cout << "             #";
    prepoctiSouradniceAVytiskni('#', hraciPole.sirka / 2 - 7, hraciPole.vyska / 2 - 2, hraciPole);
    cout << "##############";

    cout << endl;

    Cas::pockej(2000);

}
