//
// Created by gilda on 28.02.2020.
//

#ifndef POO2_LABO1_ADD_H
#define POO2_LABO1_ADD_H
#include "Operator.h"

class Add : public Operator{
public:
    Add() = default;
    int operateIntToInt(int i1, int i2) const;
};


#endif //POO2_LABO1_ADD_H
