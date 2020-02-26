//
// Created by gilda on 25.02.2020.
//

#include "Matrix.h"
#include <stdlib.h>

using namespace std;

ostream& operator<<(ostream& os, const Matrix& m){
    for(int c = 0; i < cols; ++c){
        for(int r = 0; r < rows; ++r){
            os << (to_string(values[i]) + " ");
        }
        os << endl;
    }
    os << endl;
}

Matrix::Matrix(int rows, int cols, int mod) {
    srand (time(NULL));
    this->cols = cols;
    this->rows = rows;
    this->mod = mod;
    values = new int[rows * cols];
    for(int i = 0; i < rows * cols; ++i){
        values[i] = rand() % mod;
    }
}

Matrix::~Matrix(){
    delete[] values;
}

Matrix::Matrix& operator=(const Matrix& other){
    mod = other->mod;
    cols = other->cols;
    rows = other->rows;
    delete[] values; //desalloc ancien
    values = new int[other->rows * other->cols]; //alloc nouveau
    for (int i = 0; i < rows*cols; ++i) { //copie valeurs
        values[i] = other->values[i];
    }
}

Matrix::int getItem(const Matrix& m,int row, int col){
    if(m->rows <= row || m->cols <= col){
        return 0;
    }
    return values[row][col];
}

Matrix::Matrix multiply(const Matrix& other){
    int maxRow = max(this->row, other->row);
    int maxCol = max(this->col, other->col);
}