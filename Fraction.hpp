#include "./Fraction/Fraction.cpp"
//int
class Fraction: public dev::Fraction<int>{
public:
        Fraction(int numerator, int denominator): dev::Fraction<int>(numerator, denominator){};
        Fraction():Fraction(0,1){};
        Fraction(int number):Fraction(number,1){};
        Fraction(const Fraction& fraction): Fraction(fraction.numerator, fraction.denominator){};
        Fraction(double number): dev::Fraction<int>(number){};
};