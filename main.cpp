#include <iostream>
#include "Had.h"
#include "HraciPole.h"
#include "Hra.h"

using namespace std;

int main() {
    Had hlavniHad(Souradnice(10, 10));
    HraciPole hlavniHraciPole(20, 20);

    while (true) {

        if (!hlavniHraciPole.existujeJidlo()) {
            do {
                hlavniHraciPole.vygenerujJidlo();
            } while (!jidloNeniTamCoJeHad(hlavniHad, hlavniHraciPole));
        }

        vykresliHru(hlavniHad, hlavniHraciPole);
        int vstup;
        vstup = nactiVstup();

        // TODO Stejný směr

        if (!hlavniHad.pohniSe(vstup, hlavniHraciPole)) {
            //TODO Když nabourá sám do sebe
            break;
        }

        if (narazilDoSteny(hlavniHad, hlavniHraciPole)) {
            //TODO Když narazí do stěny
            break;
        }

    }

    // TODO ukládání skóre do souboru.


    // TODO NTH: Plynulý pohyb
    return 0;
}