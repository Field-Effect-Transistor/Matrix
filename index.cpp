#include "Matrix.hpp"

int main(void) {
    Matrix<double> a = Matrix<double>(5, 5, new double*[5]{
        new double[5]{1, 0, 3, 4, 5},
        new double[5]{5, 7, 1, 9, 10},
        new double[5]{11, 12, 13, 4, 15},
        new double[5]{16, 17, 18, 19, 20},
        new double[5]{21, 22, 23, 24, 25}
    });

    Matrix<double> b(a);
    std::cout << a.getInverse() * a << std::endl;
    return 0;
}