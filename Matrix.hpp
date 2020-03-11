/**
 * @file Matrix.hpp
 * @author Gildas Houlmann, Thibaud Franchetti
 * @brief Matrice de taille quelconque contenant des entiers
 *  compris entre 0 et une borne supérieure définie à la construction
 *  Différents opérateurs sont implémentés pour cette matrice
 * @date 2020-03-11
 * 
 */

#ifndef LABO1_MATRIX_H
#define LABO1_MATRIX_H


#include <string>
#include <iostream>
#include <functional>
#include "Operator.hpp"

class Matrix {

    /**
     * @brief Affiche une matrice. Chaque élément est séparé par
     *  un espace, les lignes sont marquées par des sauts de ligne
     * 
     * @param os Un flux
     * @param m Une matrice
     * @return std::ostream& Une référence vers le flux os
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    // Représentation interne de la matrice
    int** values;
    // Nombre de lignes
    int rows;
    // Nombre de colonnes
    int cols;
    // Modulo (mathématique) appliqué sur chaque élément de la matrice
    int mod;

public:

    // Constructeurs

    /**
     * @brief Construit une nouvelle matrice de taille rows x cols
     *  remplie de nombres entiers aléatoires dans l'intervalle [0,mod[
     * 
     * @param rows Nombre de lignes
     * @param cols Nombre de colonnes
     * @param mod Modulo appliqué sur chaque élément
     * 
     * @throw runtime_error Si le nombre de lignes ou de colonnes est 
     *  inférieur à 0 ou si le modulo est inférieur ou égal à 0
     */
    Matrix(int rows, int cols, int mod);

    /**
     * @brief Constructeur de copie
     * 
     * @param other Une autre matrice
     */
    Matrix(const Matrix& other);

    /**
     * @brief Destructeur
     */
    ~Matrix();

    /**
     * @brief Opérateur d'affectation
     * 
     * @param other Une autre matrice
     * @return Matrix& Une référence vers la matrice actuelle modifiée
     */
    Matrix& operator=(const Matrix& other);

    // Opérateurs et fonction d'addition

    /**
     * @brief Additionne la matrice avec une matrice other donnée
     * et renvoie une nouvelle matrice
     * 
     * @param other Une matrice
     * @return Matrix Une nouvelle matrice
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix operator+(const Matrix& other) const;

    /**
     * @brief Additionne la matrice avec une matrice other donnée
     *  et renvoie une référence vers la matrice actuelle modifiée
     * 
     * @param other Une matrice
     * @return Matrix& Une référence vers la matrice actuelle
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix& operator+=(const Matrix& other);

    /**
     * @brief Additionne la matrice avec une matrice other donnée
     *  et renvoie un pointeur vers une nouvelle matrice allouée
     *  dynamiquement
     * 
     * @param other Une matrice
     * @return Matrix* Une nouvelle matrice allouée dynamiquement
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix* add(const Matrix& other) const;

    // Opérateurs et fonction de soustraction

    /**
     * @brief Soustrait une matrice other donnée à la matrice actuelle
     * et renvoie une nouvelle matrice
     * 
     * @param other Une matrice
     * @return Matrix Une nouvelle matrice
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix operator-(const Matrix& other) const;

    /**
     * @brief Soustrait une matrice other donnée à la matrice actuelle
     *  et renvoie une référence vers la matrice actuelle modifiée
     * 
     * @param other Une matrice
     * @return Matrix& Une référence vers la matrice actuelle
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix& operator-=(const Matrix& other);

    /**
     * @brief Soustrait une matrice other donnée à la matrice actuelle
     *  et renvoie un pointeur vers une nouvelle matrice allouée
     *  dynamiquement
     * 
     * @param other Une matrice
     * @return Matrix* Une nouvelle matrice allouée dynamiquement
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix* substract(const Matrix& other) const;

    // Opérateurs et fonction de multiplication

    /**
     * @brief Multiplie la matrice composante par composante avec une
     *  matrice other donnée et renvoie une nouvelle matrice
     * 
     * @param other Une matrice
     * @return Matrix Une nouvelle matrice
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix operator*(const Matrix& other) const;

    /**
     * @brief Multiplie la matrice composante par composante avec une
     *  matrice other donnée et renvoie une référence vers la matrice 
     *  actuelle modifiée
     * 
     * @param other Une matrice
     * @return Matrix& Une nouvelle matrice
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix& operator*=(const Matrix& other);

    /**
     * @brief Multiplie la matrice composante par composante avec une
     *  matrice other donnée et renvoie un pointeur vers une nouvelle 
     *  matrice allouée dynamiquement
     * 
     * @param other Une matrice
     * @return Matrix* Une nouvelle matrice allouée dynamiquement
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    Matrix* multiply(const Matrix& other) const;

private:
    // Type représentant une fonction de remplissage 
    // prenant en paramètre la ligne et la colonne 
    // de la matrice et retournant un élément adéquat
    using Filler = std::function<int(int,int)>;

    /**
     * @brief Applique une opération entre la matrice et une matrice other
     * 
     * @param other Une autre matrice
     * @param op Un opérateur à appliquer
     * @throw invalid_argument Si le modulo de la matrice actuelle
     *  est différent du modulo de la matrice other
     */
    void operate(const Matrix& other, const Operator& op);

    /**
     * @brief Retourne l'élément à la ligne row et colonne col de la matrice
     *  ou 0 un tel emplacement est hors de la matrice
     * 
     * @param row Une ligne
     * @param col Une colonne
     * @return int L'élément concerné ou 0
     */
    int getItem(int row, int col) const ;


    /**
     * @brief Supprime l'attribut values actuel et en attribue dynamiquement
     *  un nouveau de taille rows x cols pour lequel chaque élément est 
     *  déterminé par un appel à la fonction filler
     * 
     * @param rows Nombre de lignes de la nouvelle matrice
     * @param cols Nombre de colonnes de la nouvelle matrice
     * @param filler Fonction retournant un élément pour chaque emplacement
     *  de la nouvelle matrice
     */
    void reallocate(int rows, int cols, const Filler& filler);

    /**
     * @brief Supprimer l'attribut values
     * 
     */
    void destroyValues();

    /**
     * @return int Un nombre aléatoire dans l'intervalle [0, mod[
     */
    int getRand(int, int);
};


#endif //LABO1_MATRIX_H
