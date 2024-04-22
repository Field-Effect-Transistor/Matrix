#include "Matrix.hpp"

int main(void) {
    Matrix<float> a = Matrix<float>(5, 5, new float*[5]{
        new float[5]{1, 0, 3, 4, 5},
        new float[5]{5, 7, 1, 9, 10},
        new float[5]{11, 12, 13, 4, 15},
        new float[5]{16, 17, 18, 19, 20},
        new float[5]{21, 22, 23, 24, 25}
    });



    Matrix<float> b(a);
    std::cout << a.getDeterminant() << std::endl;
    return 0;
}