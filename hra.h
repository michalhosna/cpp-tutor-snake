#include <string>
#include "Had.h"
#include "HraciPole.h"
#include "Souradnice.h"

#ifndef BARTIKOVA_SNAKE_HRA_H
#define BARTIKOVA_SNAKE_HRA_H

const char ZNAK_HRANICE = '#';
const char ZNAK_HAD = 'X';
const char ZNAK_HAD_HLAVA = 'O';
const char ZNAK_JIDLO = '*';
const int OFFSET_POCATKU_X = 8;
const int OFFSET_POCATKU_Y = 4;

char nactiVstup();

bool narazilDoSteny(Had had, HraciPole hraciPole);

void vykresliHru(Had &had, HraciPole &hraciPole);

bool jidloNeniTamCoJeHad(Had &had, HraciPole &hraciPole);

void prepoctiSouradniceAVytiskni(char symbol, int x, int y, HraciPole &hraciPole);

void vykresliPole(HraciPole &hraciPole);

void vykresliHada(Had &had, HraciPole &hraciPole);

void gameOver(HraciPole &hraciPole);

#endif //BARTIKOVA_SNAKE_HRA_H
