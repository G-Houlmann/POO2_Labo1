//
// Created by gilda on 26.02.2020.
//

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

    cout << "one + tow" << endl << one + two << endl;

    cout << "one - tow" << endl << one - two << endl;

    cout << "one * tow" << endl << one * two << endl;

    Matrix* mptr1 = one.add(two);
    Matrix* mptr2 = one.substract(two);
    Matrix* mptr3 = one.multiply(two);

    cout << "dynamic one + tow" << endl << *mptr1 << endl;

    cout << "dynamic one - tow" << endl << *mptr2 << endl;

    cout << "dynamic one * tow" << endl << *mptr3 << endl;

    delete(mptr1);
    delete(mptr2);
    delete(mptr3);

    Matrix mDiffMod(2, 2, MODULUS + 1);

    //Uncomment next line to try to operate two Matrixes with different modulus
    //cout << "Add with two different modulus" << endl << one + mDiffMod << endl;



    return 0;
}