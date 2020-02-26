//
// Created by gilda on 25.02.2020.
//

#ifndef LABO1_MATRIX_H
#define LABO1_MATRIX_H


#include <string>
#include <iostream>

class Matrix {

    friend ostream& operator<<(ostream& os, const Matrix& m);

    int* values;
    int mod;
    int rows;
    int cols;

public:

    Matrix(int rows, int cols, int mod);
    ~Matrix();
    Matrix& operator=(const Matrix& other);

    Matrix operator+(const Matrix& other) const; // Matrix newM = m1 + m2
    //Matrix* operator+(const Matrix& other) const; // Matrix* newMp = m1 + m2
    Matrix& operator+=(const Matrix& other); // myM += m1


private:

    int getItem(int row, int col);
};


#endif //LABO1_MATRIX_H