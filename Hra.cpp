
#include <cstdio>
#include <cstdlib>
#include "Hra.h"
#include <iostream>


#ifdef _WIN32

#include <windows.h>

void nastavKurzor( int x, int y )
  {
  COORD p = { x, y };
  SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
  }

void clearScreen(){
    system("CLS");
}

char getChar() {
    char p;
    p = _getch();
    return p;
}

#else

#include <unistd.h>
#include <term.h>
#include <ncurses.h>

void nastavKurzor(int x, int y) {
    int err;
    if (!cur_term)
        if (setupterm(NULL, STDOUT_FILENO, &err) == ERR)
            return;
    putp(tparm(tigetstr(const_cast<char *>("cup")), y, x, 0, 0, 0, 0, 0, 0, 0));
}

void clearScreen() {
    system("clear");
}

//TODO
char getChar() {
    return getchar();
}

#endif

char nactiVstup() {
    while (true) {
        char klavesa = getChar();
        switch (klavesa) {
            case 'w':
                return Souradnice::SMER_NAHORU;
            case 'a':
                return Souradnice::SMER_DOLEVA;
            case 's':
                return Souradnice::SMER_DOLU;
            case 'd':
                return Souradnice::SMER_DOPRAVA;
            default:
                break;
        }
    }
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


void prepoctiSouradniceANastavKurzor(int x, int y, HraciPole &hraciPole) {
    nastavKurzor(x + OFFSET_POCATKU, hraciPole.vyska + OFFSET_POCATKU - y);
}


void vykresliPole(HraciPole &hraciPole) {
    for (int i = -1; i <= hraciPole.sirka; ++i) {
        prepoctiSouradniceANastavKurzor(i, hraciPole.vyska, hraciPole);
        std::cout << ZNAK_HRANICE;
        prepoctiSouradniceANastavKurzor(i, -1, hraciPole);
        std::cout << ZNAK_HRANICE;
    }

    for (int i = 0; i < hraciPole.vyska; ++i) {
        prepoctiSouradniceANastavKurzor(-1, i, hraciPole);
        std::cout << ZNAK_HRANICE;
        prepoctiSouradniceANastavKurzor(hraciPole.sirka + 1, i, hraciPole);
        std::cout << ZNAK_HRANICE;
    }

    prepoctiSouradniceANastavKurzor(hraciPole.jidlo->x, hraciPole.jidlo->y, hraciPole);
    std::cout << ZNAK_JIDLO;

}

void vykresliHada(Had &had, HraciPole &hraciPole) {
    Had::ClanekHada *clanek = had.prvniClanek;
    while (clanek) {
        prepoctiSouradniceANastavKurzor(clanek->souradnice.x, clanek->souradnice.y, hraciPole);
        std::cout << ZNAK_HADA;
        clanek = clanek->dalsiClanek;
    }
}

void vykresliHru(Had &had, HraciPole &hraciPole) {
    clearScreen();
    vykresliPole(hraciPole);
    vykresliHada(had, hraciPole);
}
