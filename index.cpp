#include "Matrix.hpp"
#include "Fraction.hpp"

//TODO: operator>>
//rang
    
int main(void) {
    Matrix<Fraction> a(5, 5, new Fraction*[5]{
        new Fraction[5]{1.20, 0, 3, 4, 5},
        new Fraction[5]{5, 7, 1, 9, 0xA},
        new Fraction[5]{11, 12, 13, 4, 15},
        new Fraction[5]{16, 17, 18, 19, 20},
        new Fraction[5]{21, 22, 23, 24, 25}
    });//*/    
    /*Matrix<dev::Fraction<long>> a(5, 5, new dev::Fraction<long>*[5]{
        new dev::Fraction<long>[5]{1.20, 0, 3, 4, 5},
        new dev::Fraction<long>[5]{5, 7, 1, 9, 0xA},
        new dev::Fraction<long>[5]{11, 12, 13, 4, 15},
        new dev::Fraction<long>[5]{16, 17, 18, 19, 20},
        new dev::Fraction<long>[5]{21, 22, 23, 24, 25}
    });//*/
    /*
    Matrix<double> a(5, 5, new double*[5]{
        new double[5]{1.2, 0, 3, 4, 5},
        new double[5]{5, 7, 1, 9, 10},
        new double[5]{11, 12, 13, 4, 15},
        new double[5]{16, 17, 18, 19, 20},
        new double[5]{21, 22, 23, 24, 25}
    });//*/

    std::cout << a.getInverse() * a << std::endl;
    //std::cout << a.getAdjoint() << std::endl;
    return 0;
}