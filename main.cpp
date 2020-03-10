//
// Created by gilda on 26.02.2020.
//

#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){
    srand (time(nullptr));


    Matrix m(2, 2, 5);
    Matrix m2(3, 3, 5);

    Matrix me4t(m);
    me4t = m2;

    cout << m << endl;

    cout << m2 << endl;

    Matrix* m3 = m.multiply(m2);

    cout << *m3;

    delete(m3);


    return 0;
}