//
// Created by gilda on 25.02.2020.
//

#include "Matrix.h"
#include "Add.h"
#include "Substract.h"
#include "Multiply.h"
#include <cstdlib>

using namespace std;


ostream& operator<<(ostream& os, const Matrix& m){
    for(int c = 0; c < m.cols; ++c){
        for(int r = 0; r < m.rows; ++r){
            os << (to_string(m.getItem(r, c)) + " ");
        }
        os << endl;
    }
    os << endl;
    return os;
}


Matrix::Matrix(int rows, int cols, int mod) 
    : values(nullptr), rows(rows), cols(cols), mod(mod) {

    reallocate(rows, cols, bind(&Matrix::getRand, *this, placeholders::_1, placeholders::_2));
}


Matrix::Matrix(const Matrix& other)
    : values(nullptr), rows(other.rows), cols(other.cols), mod(other.mod) {
    
    reallocate(rows, cols, bind(&Matrix::getItem, other, placeholders::_1, placeholders::_2));
}

Matrix::~Matrix(){
    destroyValues();
}

Matrix& Matrix::operator=(const Matrix& other){
    //désallocation
    for(int i = 0; i < rows; ++i) {
        delete [] values[i];
    }
    destroyValues();

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
    return *this;
}
//Additions
Matrix& Matrix::operator+=(const Matrix& other){
    Add op;
    this->operate(other, op);
    return *this;
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
    Substract op;
    this->operate(other, op);
    return *this;
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
    Multiply op;
    this->operate(other, op);
    return *this;
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


void Matrix::operate(const Matrix& other, const Operator& op){
    if(this->mod != other.mod) throw invalid_argument("Les modulos ne sont pas identiques\n");

    int maxRow = max(this->rows, other.rows);
    int maxCol = max(this->cols, other.cols);
    if(this->rows < maxRow || this ->cols < maxCol){
        reallocate(maxRow, maxCol, bind(&Matrix::getItem, *this, placeholders::_1, placeholders::_2));
    }

    for(int row = 0; row < maxRow; ++row){
        for(int col = 0; col < maxCol; ++col){
            this->values[row][col] = op.mod(op.operateIntToInt(getItem(row, col), other.getItem(row, col)), mod);
        }
    }
}

//TODO redondant avec les constructeurs ? créer une méthode plus générale pour allouer dynamiquement
void Matrix::reallocate(int row, int col, Func filler){
    int** newValues = new int*[row];
    for(int i = 0; i < row; ++i){
        newValues[i] = new int[col];
        for(int j = 0; j < col; ++j){
            newValues[i][j] = filler(i, j);
        }
    }
    this->rows = row;
    this->cols = col;
    destroyValues();
    swap(values, newValues);
}

void Matrix::destroyValues(){
    if (values != nullptr) {
        for(int i = 0; i < rows; ++i){
            delete[] values[i];
        }
        delete[] values;
    }
}

int Matrix::getRand(int, int){
    return (int) (rand() / (RAND_MAX + 1.0) * mod);
}


