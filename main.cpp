#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "LinearSystem.hpp"

int main() {
    // Solve: 2x + y = 5, x + 3y = 6
    Matrix A(2, 2);
    A(1, 1) = 2; A(1, 2) = 1;
    A(2, 1) = 1; A(2, 2) = 3;

    Vector b(2);
    b(1) = 5;
    b(2) = 6;

    LinearSystem sys(A, b);
    Vector x = sys.Solve();

    std::cout << "Nghiem x: ";
    for (int i = 1; i <= x.size(); ++i) {
        std::cout << x(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
