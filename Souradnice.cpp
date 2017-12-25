//
// Created by Michal Hosna on 25/12/2017.
//

#include "Souradnice.h"

bool Souradnice::operator==(const Souradnice &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Souradnice::operator!=(const Souradnice &rhs) const {
    return !(rhs == *this);
}

Souradnice::Souradnice(int x, int y) : x(x), y(y) {}
