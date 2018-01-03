#ifndef BARTIKOVA_SNAKE_TABULKASKORE_H
#define BARTIKOVA_SNAKE_TABULKASKORE_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class TabulkaSkore {
    const static unsigned int MAX_DELKA_JMENA = 20;

    class Hrac {
    public:
        string jmeno;
        int skore;

        Hrac(const string &jmeno, const int skore);

        bool operator<(const Hrac &rhs) const;

        bool operator>(const Hrac &rhs) const;

        bool operator<=(const Hrac &rhs) const;

        bool operator>=(const Hrac &rhs) const;
    };

    vector<Hrac> poleHracu;
public:
    void nactiSkore(const string &cestaKSouboru);

    void ulozSkore(const string &cestaKSouboru, unsigned int limit = 10);

    void pridejSkore(const string &jmeno, const int &skore);

    void vytiskniSkore();


};


#endif //BARTIKOVA_SNAKE_TABULKASKORE_H
