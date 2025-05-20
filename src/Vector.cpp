#include "Vector.hpp"
#include <cassert>

// Constructor
Vector::Vector(int size) : mSize(size) {
    assert(size > 0);
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i) mData[i] = 0.0;
}

// Destructor
Vector::~Vector() {
    delete[] mData;
}

// Copy constructor
Vector::Vector(const Vector& other) : mSize(other.mSize) {
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i) mData[i] = other.mData[i];
}

// Assignment operator
Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] mData;
    mSize = other.mSize;
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i) mData[i] = other.mData[i];
    return *this;
}

// Element access (zero-based)
double& Vector::operator[](int index) {
    assert(index >= 0 && index < mSize);
    return mData[index];
}
const double& Vector::operator[](int index) const {
    assert(index >= 0 && index < mSize);
    return mData[index];
}

// Element access (one-based)
double& Vector::operator()(int index) {
    assert(index > 0 && index <= mSize);
    return mData[index - 1];
}

// Get size
int Vector::size() const {
    return mSize;
}

// Addition
Vector Vector::operator+(const Vector& other) const {
    assert(mSize == other.mSize);
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) result.mData[i] = mData[i] + other.mData[i];
    return result;
}

// Subtraction
Vector Vector::operator-(const Vector& other) const {
    assert(mSize == other.mSize);
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) result.mData[i] = mData[i] - other.mData[i];
    return result;
}

// Scalar multiplication
Vector Vector::operator*(double scalar) const {
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) result.mData[i] = mData[i] * scalar;
    return result;
}
