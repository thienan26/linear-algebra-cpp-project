#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"

class Matrix {
private:
    int mNumRows;
    int mNumCols;
    double** mData;

public:
    Matrix(int numRows, int numCols);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    double& operator()(int row, int col);
    int numRows() const;
    int numCols() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Vector operator*(const Vector& vec) const;
};

#endif
