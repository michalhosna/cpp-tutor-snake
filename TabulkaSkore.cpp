#include "TabulkaSkore.h"
#include "console.h"
#include <iostream>
#include <iomanip>

using namespace std;

TabulkaSkore::Hrac::Hrac(const string &jmeno, const int skore) : jmeno(jmeno), skore(skore) {}

bool TabulkaSkore::Hrac::operator<(const TabulkaSkore::Hrac &rhs) const {
    return skore < rhs.skore;
}

bool TabulkaSkore::Hrac::operator>(const TabulkaSkore::Hrac &rhs) const {
    return rhs < *this;
}

bool TabulkaSkore::Hrac::operator<=(const TabulkaSkore::Hrac &rhs) const {
    return !(rhs < *this);
}

bool TabulkaSkore::Hrac::operator>=(const TabulkaSkore::Hrac &rhs) const {
    return !(*this < rhs);
}

void TabulkaSkore::nactiSkore(const string &cestaKSouboru) {
    ifstream soubor;
    soubor.open(cestaKSouboru);
    if (!soubor.is_open()) {
        return;
    }

    while (!soubor.eof()) {
        string jmeno;
        int skore;
        getline(soubor, jmeno);
        if (jmeno.length() <= 0) break;
        soubor >> skore;

        // Peek nahlídne na další pozici souboru, ale neodeberejíz bufferu.
        if (soubor.peek() == '\n') soubor.get();

        this->poleHracu.emplace_back(jmeno, skore);
    }
}

void TabulkaSkore::ulozSkore(const string &cestaKSouboru, unsigned int limit) {
    ofstream soubor;
    soubor.open(cestaKSouboru, fstream::out);
    soubor.clear();
    if (!soubor.is_open()) {
        throw "Otevření souboru nevyšlo";
    }

    for (int j = 0; j < limit && j < poleHracu.size(); ++j) {
        soubor << this->poleHracu[j].jmeno << endl << this->poleHracu[j].skore << endl;
    }
}

void TabulkaSkore::pridejSkore(const string &jmeno, const int &skore) {
    this->poleHracu.emplace_back(Hrac(jmeno, skore));

    // Sort a reverse dohromady zajistí, že nově přiadný hráč, bude mezi hráči se stejným skoré nejvýše
    sort(this->poleHracu.begin(), this->poleHracu.end());
    reverse(this->poleHracu.begin(), this->poleHracu.end());
}

void TabulkaSkore::vytiskniSkore() {
    vymazObrazovku();
    cout << "TOP SKORE" << endl << "=========" << endl << endl;

    for (auto i : this->poleHracu) {
        cout.width(MAX_DELKA_JMENA + 1);
        cout << left << i.jmeno;
        cout.width(5);
        cout << right << i.skore << endl;
    }

    cout << endl;
}
