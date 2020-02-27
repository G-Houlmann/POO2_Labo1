//
// Created by gilda on 26.02.2020.
//

#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){

    Matrix m(2, 2, 5);

    Matrix m2 = m;

    cout << m + m << endl;

    cout << m << endl;


    return 0;
}