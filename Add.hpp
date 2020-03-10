/**
 * @file Add.hpp
 * @author Gildas Houlmann, Thibaud Franchetti
 * @brief Opérateur d'addition sur les entiers
 * @date 2020-03-11
 * 
 */

#ifndef POO2_LABO1_ADD_H
#define POO2_LABO1_ADD_H
#include "Operator.hpp"

class Add : public Operator{
public:
    Add() = default;

    /**
     * @param i1 Un entier
     * @param i2 Un entier
     * @return int L'addition des entiers i1 et i2
     *  La fonction ne vérifie pas les débordements
     */
    int operateIntToInt(int i1, int i2) const;
};


#endif //POO2_LABO1_ADD_H
