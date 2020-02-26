//
// Created by gilda on 25.02.2020.
//

#include "Matrix.h"
#include <stdlib.h>

using namespace std;

ostream& operator<<(ostream& os, const Matrix& m){
    for(int c = 0; c < m.cols; ++c){
        for(int r = 0; r < m.rows; ++r){
            os << (to_string(m.getItem(r, c)) + " ");
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

Matrix& Matrix::operator=(const Matrix& other){
    mod = other.mod;
    cols = other.cols;
    rows = other.rows;
    delete[] values; //desalloc ancien
    values = new int[other.rows * other.cols]; //alloc nouveau
    for (int i = 0; i < rows*cols; ++i) { //copie valeurs
        values[i] = other.values[i];
    }
}

int Matrix::getItem(int row, int col) const{
    if(this->rows <= row || this->cols <= col){
        return 0;
    }
    return values[cols * row + col];
}

Matrix Matrix::operate(const Matrix& other, int (*f)(int, int)){
    int maxRow = max(this->rows, other.rows);
    int maxCol = max(this->cols, other.cols);

    for(int row = 0; row < maxRow; ++row){

    }
}

Matrix Matrix::multiply(const Matrix& other){

}

int Matrix::multiply(int x, int y) const{
    return x * y;
}

int Matrix::add(int x, int y) const{
    return x + y;
}

