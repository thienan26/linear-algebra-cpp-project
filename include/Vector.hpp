#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
private:
    int mSize;
    double* mData;

public:
    Vector(int size);
    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    double& operator[](int index);
    const double& operator[](int index) const;
    double& operator()(int index);
    int size() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
};

#endif
