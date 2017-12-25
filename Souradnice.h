#ifndef BARTIKOVA_SNAKE_SOURADNICE_H
#define BARTIKOVA_SNAKE_SOURADNICE_H


class Souradnice {
public:
    const static int SMER_NAHORU = 0;
    const static int SMER_DOPRAVA = 1;
    const static int SMER_DOLU = 2;
    const static int SMER_DOLEVA = 3;

    int x, y;

    Souradnice(int x, int y);

    bool operator==(const Souradnice &rhs) const;

    bool operator!=(const Souradnice &rhs) const;
};


#endif //BARTIKOVA_SNAKE_SOURADNICE_H
