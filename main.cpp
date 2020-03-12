/**
 * @file main.cpp
 * @author Gildas Houlmann, Thibaud Franchetti
 * @brief Programme de test de la classe Matrix
 * @date 2020-03-11
 * 
 */

#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main(){

    const int MODULUS = 5;

    Matrix one(2, 2, MODULUS);
    Matrix two(3, 3, MODULUS);

    cout << "modulus is " << MODULUS << endl;

    cout << "one" << endl << one << endl;

    cout << "two" << endl << two << endl;

    cout << "one + two" << endl << one + two << endl;

    cout << "one - two" << endl << one - two << endl;

    cout << "one * two" << endl << one * two << endl;

    Matrix* mptr1 = one.add(two);
    Matrix* mptr2 = one.substract(two);
    Matrix* mptr3 = one.multiply(two);

    cout << "dynamic one + two" << endl << *mptr1 << endl;

    cout << "dynamic one - two" << endl << *mptr2 << endl;

    cout << "dynamic one * two" << endl << *mptr3 << endl;

    delete(mptr1);
    delete(mptr2);
    delete(mptr3);

    Matrix mDiffMod(2, 2, MODULUS + 1);

    cout << "Add with two different modulus" << endl;
    try {
         cout << one + mDiffMod << endl;
    } catch (const invalid_argument& e) {
        cout << "An error occured : " << e.what() << endl;
    }

    return 0;
}