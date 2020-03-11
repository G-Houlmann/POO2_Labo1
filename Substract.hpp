/**
 * @file Substract.hpp
 * @author Gildas Houlmann, Thibaud Franchetti
 * @brief Opérateur de soustraction sur les entiers
 * @date 2020-03-11
 * 
 */

#ifndef POO2_LABO1_SUBSTRACT_H
#define POO2_LABO1_SUBSTRACT_H
#include "Operator.hpp"

class Substract: public Operator {
public:
    Substract()= default;

    /**
     * @param i1 Un entier
     * @param i2 Un entier
     * @return int La différence entre les entiers i1 et i2
     *  La fonction ne vérifie pas les débordements
     */
    int operateIntToInt(int i1, int i2) const;
};


#endif //POO2_LABO1_SUBSTRACT_H
