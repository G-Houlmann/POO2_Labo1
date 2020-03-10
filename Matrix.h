//
// Created by gilda on 25.02.2020.
//

#ifndef LABO1_MATRIX_H
#define LABO1_MATRIX_H


#include <string>
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <functional>
#include "Operator.h"

class Matrix {

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    int** values;
    int rows;
    int cols;
    int mod;

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
    typedef std::function<int(int,int)> Func;

    void operate(const Matrix& other, const Operator& op);

    int getItem(int row, int col) const ;

    void reallocate(int rows, int cols, Func filler);

    void destroyValues();

    static int getRand(int mod, int, int);
};


#endif //LABO1_MATRIX_H
