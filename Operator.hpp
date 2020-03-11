/**
 * @file Operator.hpp
 * @author Gildas Houlmann, Thibaud Franchetti
 * @brief Classe abstraite définissant le concept d'opérateur
 *  sur les nombres entiers
 * @date 2020-03-11
 * 
 */

#ifndef POO2_LABO1_OPERATOR_H
#define POO2_LABO1_OPERATOR_H
#include <string>

class Operator {
public:

    Operator() {};

    /**
     * @brief Un opérateur sur les entiers
     * 
     * @param i1 Un entier
     * @param i2 Un entier
     * @return int Résultat de l'opération
     */
    virtual int operateIntToInt(int i1, int i2) const = 0;
};


#endif //POO2_LABO1_OPERATOR_H
