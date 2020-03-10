/**
 * @file Multiply.hpp
 * @author Gildas Houlmann, Thibaud Franchetti
 * @brief Opérateur de multiplication sur les entiers
 * @date 2020-03-11
 * 
 */

#ifndef POO2_LABO1_MULTIPLY_H
#define POO2_LABO1_MULTIPLY_H
#include "Operator.hpp"

class Multiply: public Operator {
public:
    Multiply() = default;

    /**
     * @param i1 Un entier
     * @param i2 Un entier
     * @return int La multiplication de i1 et i2
     *  La fonction ne vérifie pas les débordements
     */
    int operateIntToInt(int i1, int i2) const;
};


#endif //POO2_LABO1_MULTIPLY_H
