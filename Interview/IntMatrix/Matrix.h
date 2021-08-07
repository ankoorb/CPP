//
// Created by Ankoor Bhagat on 8/6/21.
//

#ifndef INTMATRIX_MATRIX_H
#define INTMATRIX_MATRIX_H

#include <iostream>
#include <vector>
#include <cassert>

class Matrix {
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
private:
    unsigned rows_;
    unsigned cols_;
    std::vector<std::vector<int>> data_;

public:
    // Constructors
    Matrix(unsigned rows, unsigned cols, int initial);
    Matrix(const Matrix& other);

    // Getters
    unsigned getRows() const;
    unsigned getCols() const;

    static Matrix Identity(unsigned rows, unsigned cols);

    // Transpose
    Matrix Transpose();

    // Convolve
    static Matrix Conv(const Matrix& image, const Matrix& kernel);

    // Matrix Matrix mathematical operations
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    // Matrix Vector mathematical operations
    std::vector<int> operator*(const std::vector<int>& vec);

    // Matrix Scalar mathematical operations
    Matrix operator+(const int& scalar);
    Matrix operator-(const int& scalar);
    Matrix operator*(const int& scalar);
    Matrix operator/(const int& scalar);

    // Accessors
    int& operator()(const unsigned& row, const unsigned& col);
    const int& operator()(const unsigned& row, const unsigned& col) const;

};



#endif //INTMATRIX_MATRIX_H
