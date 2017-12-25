#include "HraciPole.h"
#include <stdlib.h>
#include <time.h>

HraciPole::HraciPole(unsigned int sirka, unsigned int vyska) : sirka(sirka), vyska(vyska), jidlo(nullptr) {
}

void HraciPole::vygenerujJidlo() {
    srand(static_cast<unsigned int>(time(nullptr)));
    if (existujeJidlo()) {
        delete this->jidlo;
    }
    this->jidlo = new Souradnice(rand() % this->sirka, rand() % this->vyska);
}

bool HraciPole::existujeJidlo() {
    return this->jidlo != nullptr;
}
