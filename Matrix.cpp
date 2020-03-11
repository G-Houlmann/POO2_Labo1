/**
 * @file Matrix.cpp
 * @author Gildas Houlmann, Thibaud Franchetti
 * @brief Implémentation de la classe Matrix
 * @date 2020-03-11
 * 
 */

#include "Matrix.hpp"
#include "Add.hpp"
#include "Substract.hpp"
#include "Multiply.hpp"
#include <time.h>
#include <stdexcept>
#include <cstdlib>

using namespace std;


/*
    Fonction outil implémentant une version mathématique
    De l'opérateur %
*/
int modulo(int n, int mod) {
    int tmp = n % mod;
    return tmp < 0 ? tmp + mod : tmp;
}

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

    if (rows < 0) throw runtime_error("Le nombre de lignes doit être positif ou nul");
    if (cols < 0) throw runtime_error("Le nombre de colonnes doit être positif ou nul");
    if (mod <= 0) throw runtime_error("Le modulo doit être strictement positif");

    srand(time(nullptr));

    // Alloue dynamiquement un nouveau tableau de taille rows x cols
    // Les valeurs sont fournies par la méthode getRand
    reallocate(rows, cols, bind(&Matrix::getRand, ref(*this), placeholders::_1, placeholders::_2));
}


Matrix::Matrix(const Matrix& other)
    : values(nullptr), rows(other.rows), cols(other.cols), mod(other.mod) {
    
    if(this != &other)
        reallocate(rows, cols, bind(&Matrix::getItem, ref(other), placeholders::_1, placeholders::_2));
}

Matrix::~Matrix(){
    destroyValues();
}

Matrix& Matrix::operator=(const Matrix& other){
    if (this != &other) {
        this->mod = other.mod;
        reallocate(rows, cols, bind(&Matrix::getItem, ref(other), placeholders::_1, placeholders::_2));
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
        reallocate(maxRow, maxCol, bind(&Matrix::getItem, ref(*this), placeholders::_1, placeholders::_2));
    }

    for(int row = 0; row < maxRow; ++row){
        for(int col = 0; col < maxCol; ++col){
            this->values[row][col] = modulo(op.operateIntToInt(getItem(row, col), other.getItem(row, col)), mod);
        }
    }
}

void Matrix::reallocate(int rows, int cols, const Filler& filler){
    // Alloue dynamiquement et remplit values
    int** newValues = new int*[rows];
    for(int i = 0; i < rows; ++i){
        newValues[i] = new int[cols];
        for(int j = 0; j < cols; ++j){
            newValues[i][j] = filler(i, j);
        }
    }

    this->rows = rows;
    this->cols = cols;
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


