#include "Matrix.hpp"
#include <cassert>

// Constructor
Matrix::Matrix(int numRows, int numCols)
    : mNumRows(numRows), mNumCols(numCols) {
    assert(numRows > 0 && numCols > 0);
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j) {
            mData[i][j] = 0.0;
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < mNumRows; ++i) {
        delete[] mData[i];
    }
    delete[] mData;
}

// Copy constructor
Matrix::Matrix(const Matrix& other)
    : mNumRows(other.mNumRows), mNumCols(other.mNumCols) {
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j)
            mData[i][j] = other.mData[i][j];
    }
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    for (int i = 0; i < mNumRows; ++i) delete[] mData[i];
    delete[] mData;
    mNumRows = other.mNumRows;
    mNumCols = other.mNumCols;
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j)
            mData[i][j] = other.mData[i][j];
    }
    return *this;
}

// Element access (1-based indexing)
double& Matrix::operator()(int row, int col) {
    assert(row > 0 && row <= mNumRows);
    assert(col > 0 && col <= mNumCols);
    return mData[row - 1][col - 1];
}

int Matrix::numRows() const { return mNumRows; }
int Matrix::numCols() const { return mNumCols; }

// Addition
Matrix Matrix::operator+(const Matrix& other) const {
    assert(mNumRows == other.mNumRows && mNumCols == other.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] + other.mData[i][j];
    return result;
}

// Subtraction
Matrix Matrix::operator-(const Matrix& other) const {
    assert(mNumRows == other.mNumRows && mNumCols == other.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] - other.mData[i][j];
    return result;
}

// Scalar multiplication
Matrix Matrix::operator*(double scalar) const {
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] * scalar;
    return result;
}

// Matrix * Vector
Vector Matrix::operator*(const Vector& vec) const {
    assert(mNumCols == vec.size());
    Vector result(mNumRows);
    for (int i = 0; i < mNumRows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < mNumCols; ++j) {
            sum += mData[i][j] * vec[j];
        }
        result[i] = sum;
    }
    return result;
}