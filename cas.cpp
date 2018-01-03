#include "cas.h"

void Cas::pockej(unsigned int msekund) {
    high_resolution_clock::time_point zacatek = high_resolution_clock::now();

    while (((duration<double, std::milli>) (high_resolution_clock::now() - zacatek)).count() < msekund);
}

void Cas::vyresetujPocitadlo() {
    this->casResetu = high_resolution_clock::now();
}

bool Cas::uzUplynuloMilisekund(unsigned int msekund) {
    return ((duration<double, std::milli>) (high_resolution_clock::now() - this->casResetu)).count() >= msekund;
}

Cas::Cas() { vyresetujPocitadlo(); }
