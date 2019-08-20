#include <iostream>
#include "Had.h"
#include "hra.h"
#include "TabulkaSkore.h"
#include "console.h"
#include "Cas.h"

#define SOUBOR_SE_SKORE "tabulka_skore.txt"

using namespace std;

int main() {
    Had hlavniHad(Souradnice(10, 10));
    HraciPole hlavniHraciPole(20, 20);
    Cas hlavniCasovac;

    while (true) {
        if (!hlavniCasovac.uzUplynuloMilisekund(300)) continue;

        hlavniCasovac.vyresetujPocitadlo();

        if (!hlavniHraciPole.existujeJidlo()) {
            do {
                hlavniHraciPole.vygenerujJidlo();
            } while (!jidloNeniTamCoJeHad(hlavniHad, hlavniHraciPole));
        }

        vykresliHru(hlavniHad, hlavniHraciPole);
        int vstup;
        vstup = nactiVstup();


        if (!hlavniHad.pohniSe(vstup, hlavniHraciPole)) {
            gameOver(hlavniHraciPole);
            break;
        }

        if (narazilDoSteny(hlavniHad, hlavniHraciPole)) {
            gameOver(hlavniHraciPole);
            break;
        }

    }

    vymazObrazovku();

    cout << "Zadej jmeno: \n";
    string jmeno;
    getline(cin, jmeno);

    TabulkaSkore tabulkaSkore;

    tabulkaSkore.nactiSkore(SOUBOR_SE_SKORE);
    tabulkaSkore.pridejSkore(jmeno, hlavniHad.delka);
    tabulkaSkore.ulozSkore(SOUBOR_SE_SKORE);

    tabulkaSkore.vytiskniSkore();

    return 0;
}
