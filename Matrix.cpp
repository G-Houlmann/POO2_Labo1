//
// Created by gilda on 25.02.2020.
//

#include "Matrix.h"
#include <stdlib.h>

using namespace std;



int addNumbers(int x, int y){
    return x + y;
}

int substractNumbers(int x, int y){
    return x * y;
}

int multiplyNumbers(int x, int y){
    return x * y;
}

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

    //Allocation dynamique et remplissage de values
    this->values = new int*[rows];
    for(int i = 0; i < rows; ++i){
        this->values[i] = new int[cols];
        for(int j = 0; j < cols; ++j){
            this->values[i][j] = rand() % mod;
        }
    }
}


Matrix::Matrix(const Matrix& other){
    /*TODO: code redondant avec l'autre constructeur
     * Solutions : tout mettre dans un constructeur privé qui prend un tableau et le reste, et mettre random si nullptr.
     *              sauf que risque d'incohérence entre le tab et les tailles
     */

    this->cols = other.cols;
    this->rows = other.rows;
    this->mod = other.mod;

    this->values = new int*[rows];
    for(int i = 0; i < rows; ++i){
        this->values[i] = new int[cols];
        for(int j = 0; j < cols; ++j){
            this->values[i][j] = other.values[i][j];
        }
    }

}

Matrix::~Matrix(){
    for(int i = 0; i < rows; ++i) {
        delete [] values[i];
    }
    delete [] values;
}

Matrix& Matrix::operator=(const Matrix& other){
    //désallocation
    for(int i = 0; i < rows; ++i) {
        delete [] values[i];
    }
    delete [] values;

    //copie des valeurs
    mod = other.mod;
    cols = other.cols;
    rows = other.rows;

    //Allocation dynamique et copie de values
    values = new int*[rows];
    for(int i = 0; i < rows; ++i){
        values[i] = new int[cols];
        for(int j = 0; j < cols; ++j){
            values[i][j] = other.getItem(i, j);
        }
    }

}
//Additions
Matrix& Matrix::operator+=(const Matrix& other){
    this->operate(other, addNumbers);
}

Matrix Matrix::operator+(const Matrix& other) const{
    Matrix temp = *this;
    temp += other;
    return temp;
}

Matrix* Matrix::add(const Matrix& other) const {
    Matrix* temp = new Matrix(*this);
    *temp += other;
    return temp;
}

//Soustractions
Matrix& Matrix::operator-=(const Matrix& other){
    this->operate(other, substractNumbers);
}

Matrix Matrix::operator-(const Matrix& other) const{
    Matrix temp = *this;
    temp -= other;
    return temp;
}

Matrix* Matrix::substract(const Matrix &other) const {
    Matrix* temp = new Matrix(*this);
    *temp -= other;
    return temp;
}


//Multiplications composante par composante
Matrix& Matrix::operator*=(const Matrix& other){
    this->operate(other, multiplyNumbers);
}

Matrix Matrix::operator*(const Matrix& other) const{
    Matrix temp = *this;
    temp *= other;
    return temp;
}

Matrix* Matrix::multiply(const Matrix &other) const {
    Matrix* temp = new Matrix(*this);
    *temp *= other;
    return temp;
}

int Matrix::getItem(int row, int col) const{
    if(this->rows <= row || this->cols <= col){
        return 0;
    }
    return values[row][col];
}

template <typename Operator>
void Matrix::operate(const Matrix& other, Operator op){
    if(this->mod != other.mod) throw invalid_argument("Les modulos ne sont pas identiques\n");
    int maxRow = max(this->rows, other.rows);
    int maxCol = max(this->cols, other.cols);

    for(int row = 0; row < maxRow; ++row){
        for(int col = 0; col < maxCol; ++col){
            this->values[row][col] = op(getItem(row, col), other.getItem(row, col)) % mod;
        }
    }
}




