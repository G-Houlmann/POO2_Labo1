//
// Created by gilda on 28.02.2020.
//

#ifndef POO2_LABO1_OPERATOR_H
#define POO2_LABO1_OPERATOR_H
#include <string>

class Operator {
public:

    Operator() {};

    virtual int operateIntToInt(int i1, int i2) const = 0;
    virtual int mod(int i, int mod) const;
};


#endif //POO2_LABO1_OPERATOR_H
