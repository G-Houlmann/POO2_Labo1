//
// Created by gilda on 28.02.2020.
//

#ifndef POO2_LABO1_SUBSTRACT_H
#define POO2_LABO1_SUBSTRACT_H
#include "Operator.h"

class Substract: public Operator {
public:
    Substract()= default;
    int operateIntToInt(int i1, int i2) const;
    int mod(int i, int mod) const;
};


#endif //POO2_LABO1_SUBSTRACT_H
