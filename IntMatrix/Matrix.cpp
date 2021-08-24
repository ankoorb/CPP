//
// Created by Ankoor Bhagat on 8/6/21.
//

#include "Matrix.h"


Matrix::Matrix(unsigned rows, unsigned cols, int initial) {
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows_);
    for (auto i = 0; i < rows_; i++){
        data_[i].resize(cols_, initial);
    }
}

Matrix::Matrix(const Matrix &other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    data_ = other.data_;
}

std::ostream& operator<<(std::ostream& os, const Matrix& M){
    for (auto i = 0; i < M.rows_; i++){
        for (auto j = 0; j < M.cols_; j++){
            os << M.data_[i][j] << ", " << std::flush;
        }
        os << std::endl;
    }
    return os;
}

unsigned Matrix::getRows() const { return rows_; }

unsigned Matrix::getCols() const { return cols_; }

int& Matrix::operator()(const unsigned &row, const unsigned &col) { return data_[row][col]; }

const int& Matrix::operator()(const unsigned &row, const unsigned &col) const { return data_[row][col]; }

Matrix Matrix::Transpose() {
    Matrix output(cols_, rows_, 0);
    for (auto i = 0; i < cols_; i++){
        for (auto j = 0; j < rows_; j++){
            output.data_[i][j] = data_[j][i];
        }
    }
    return output;
}

Matrix Matrix::operator+(const Matrix &other) {
    assert(rows_ == other.rows_ && cols_ == other.cols_);
    Matrix output(rows_, cols_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            output.data_[i][j] = data_[i][j] + other.data_[i][j];
        }
    }
    return output;
}

Matrix Matrix::operator-(const Matrix &other) {
    assert(rows_ == other.rows_ && cols_ == other.cols_);
    Matrix output(rows_, cols_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            output.data_[i][j] = data_[i][j] - other.data_[i][j];
        }
    }
    return output;
}

Matrix Matrix::operator*(const Matrix &other) {
    assert(cols_ == other.rows_);
    Matrix output(rows_, other.cols_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < other.cols_; j++){
            for (auto k = 0; k < cols_; k++){
                output.data_[i][j] += data_[i][k] * other.data_[k][j];
            }
        }
    }
    return output;
}

Matrix& Matrix::operator+=(const Matrix &other) {
    assert(rows_ == other.rows_ && cols_ == other.cols_);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            data_[i][j] += other.data_[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix &other) {
    assert(rows_ == other.rows_ && cols_ == other.cols_);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            data_[i][j] -= other.data_[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix &other) {
    Matrix result = (*this) * other;
    (*this) = result;
    return *this;
}

Matrix Matrix::operator+(const int &scalar) {
    Matrix output(rows_, cols_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            output.data_[i][j] = data_[i][j] + scalar;
        }
    }
    return output;
}

Matrix Matrix::operator-(const int &scalar) {
    Matrix output(rows_, cols_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            output.data_[i][j] = data_[i][j] - scalar;
        }
    }
    return output;
}

Matrix Matrix::operator*(const int &scalar) {
    Matrix output(rows_, cols_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            output.data_[i][j] = data_[i][j] * scalar;
        }
    }
    return output;
}

Matrix Matrix::operator/(const int &scalar) {
    Matrix output(rows_, cols_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            output.data_[i][j] = data_[i][j] / scalar;
        }
    }
    return output;
}

Matrix Matrix::Identity(unsigned rows, unsigned cols) {
    assert(rows == cols);
    Matrix output(rows, cols, 0);
    for (auto i = 0; i < rows; i++){
        for (auto j = 0; j < cols; j++){
            if (i == j){
                output.data_[i][j] = 1;
            }
        }
    }
    return output;
}

std::vector<int> Matrix::operator*(const std::vector<int> &vec) {
    assert(cols_ == vec.size());
    std::vector<int> output(rows_, 0);
    for (auto i = 0; i < rows_; i++){
        for (auto j = 0; j < cols_; j++){
            output[i] = data_[i][j] * vec[j];
        }
    }
    return output;
}

Matrix Matrix::Conv(const Matrix &image, const Matrix &kernel) {
    assert(image.rows_ == image.cols_ && kernel.rows_ == kernel.cols_);
    unsigned n = image.rows_;
    unsigned m = kernel.rows_;
    unsigned dim = image.rows_ - kernel.rows_ + 1;
    Matrix feature(dim, dim, 0);
    for (auto i = 0; i < dim; i++){
        for (auto j = 0; j < dim; j++){
            int value = 0;
            for (auto p = i; p < i + m; p++){
                for (auto q = j; q < j + m; q++){
                    value += image.data_[p % n][q % n] * kernel.data_[p % m][q % m];
                }
            }
            feature.data_[i][j] = value;
        }
    }

    return feature;
}