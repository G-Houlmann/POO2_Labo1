//
// Created by gilda on 28.02.2020.
//

#include "Substract.h"

int Substract::operateIntToInt(int i1, int i2) const {
    return i1 - i2;
}

int Substract::mod(int i, int mod) const{
    while(i < 0) i += mod;
    return i;
}