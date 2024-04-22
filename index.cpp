#include "Matrix.hpp"

int main(void) {
    Matrix<float> a = Matrix<float>(5, 5, new float*[5]{
        new float[5]{1, 2, 3, 4, 5},
        new float[5]{6, 7, 8, 9, 10},
        new float[5]{11, 12, 13, 14, 15},
        new float[5]{16, 17, 18, 19, 20},
        new float[5]{21, 22, 23, 24, 25}
    });

    Matrix<float> b(a);
    std::cout << a << std::endl;
    std::cout << a.getSubMatrix(1, 2, 1, 2) << std::endl;
    return 0;
}