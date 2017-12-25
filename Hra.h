#include "Had.h"
#include "HraciPole.h"
#include "Souradnice.h"

#ifndef BARTIKOVA_SNAKE_HRA_H
#define BARTIKOVA_SNAKE_HRA_H

const char ZNAK_HRANICE = '#';
const char ZNAK_HADA = 'X';
const char ZNAK_JIDLO = '*';
const int OFFSET_POCATKU = 5;

char nactiVstup();

void nastavKurzor(int x, int y);

void clearScreen();

bool narazilDoSteny(Had had, HraciPole hraciPole);

void vykresliHru(Had &had, HraciPole &hraciPole);

bool jidloNeniTamCoJeHad(Had &had, HraciPole &hraciPole);

void prepoctiSouradniceANastavKurzor(int x, int y, HraciPole &hraciPole);

void vykresliPole(HraciPole &hraciPole);

void vykresliHada(Had &had, HraciPole &hraciPole);


#endif //BARTIKOVA_SNAKE_HRA_H
