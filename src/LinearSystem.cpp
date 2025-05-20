#include "LinearSystem.hpp"
#include <cassert>
#include <cmath>
#include <algorithm>

// Constructor
LinearSystem::LinearSystem(const Matrix& A, const Vector& b) {
    assert(A.numRows() == A.numCols());
    assert(A.numRows() == b.size());
    mSize = A.numRows();
    mpA = new Matrix(A);
    mpb = new Vector(b);
}

// Destructor
LinearSystem::~LinearSystem() {
    delete mpA;
    delete mpb;
}

Vector LinearSystem::Solve() {
    Matrix A(*mpA);
    Vector b(*mpb);
    Vector x(mSize);

    // Forward elimination (partial pivoting)
    for (int k = 1; k <= mSize; ++k) {
        int maxRow = k;
        double maxVal = std::abs(A(k, k));
        for (int i = k + 1; i <= mSize; ++i) {
            if (std::abs(A(i, k)) > maxVal) {
                maxVal = std::abs(A(i, k));
                maxRow = i;
            }
        }
        if (maxRow != k) {
            for (int j = 1; j <= mSize; ++j)
                std::swap(A(k, j), A(maxRow, j));
            std::swap(b[k - 1], b[maxRow - 1]);
        }
        for (int i = k + 1; i <= mSize; ++i) {
            double factor = A(i, k) / A(k, k);
            for (int j = k; j <= mSize; ++j)
                A(i, j) -= factor * A(k, j);
            b[i - 1] -= factor * b[k - 1];
        }
    }
    // Back substitution
    for (int i = mSize; i >= 1; --i) {
        double sum = b[i - 1];
        for (int j = i + 1; j <= mSize; ++j)
            sum -= A(i, j) * x[j - 1];
        x[i - 1] = sum / A(i, i);
    }
    return x;
}