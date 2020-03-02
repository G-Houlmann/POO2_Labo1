//
// Created by gilda on 28.02.2020.
//

#ifndef POO2_LABO1_MULTIPLY_H
#define POO2_LABO1_MULTIPLY_H
#include "Operator.h"

class Multiply: public Operator {
public:
    Multiply() = default;
    int operateIntToInt(int i1, int i2) const;
};


#endif //POO2_LABO1_MULTIPLY_H
