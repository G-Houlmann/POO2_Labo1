//
// Created by gilda on 25.02.2020.
//

#ifndef LABO1_MATRIX_H
#define LABO1_MATRIX_H


#include <string>
#include <iostream>
#include <time.h>
#include <stdexcept>
#include "Operator.h"

class Matrix {

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    int** values;
    int mod;
    int rows;
    int cols;


public:

    Matrix(int rows, int cols, int mod);
    Matrix(const Matrix& other);
    ~Matrix();
    Matrix& operator=(const Matrix& other);

    //additions
    Matrix operator+(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);
    Matrix* add(const Matrix& other) const;

    //soustractions
    Matrix operator-(const Matrix& other) const;
    Matrix& operator-=(const Matrix& other);
    Matrix* substract(const Matrix& other) const;

    //multiplications
    Matrix operator*(const Matrix& other) const;
    Matrix& operator*=(const Matrix& other);
    Matrix* multiply(const Matrix& other) const;

private:
    void operate(const Matrix& other, const Operator& op);

    int getItem(int row, int col) const;

    void reallocate(int rows, int cols);

    void destroyValues();

    int getRand(int mod, int unused);
};


#endif //LABO1_MATRIX_H
