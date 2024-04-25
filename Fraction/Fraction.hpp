#include <iostream>

//TODO:convert Fraction<int> to Fraction

namespace dev{
    template<typename T>
    class Fraction{
    protected:
        T numerator;
        T denominator;
    public:
        Fraction(): Fraction(0, 1) {};
        Fraction(const T& numerator, const T& denominator);
        Fraction(double number);
        Fraction(const Fraction<T>& fraction): Fraction(fraction.numerator, fraction.denominator) {};


        T getNumerator(void)const { return numerator;}
        T getDenominator(void)const { return denominator;}
        void setNumerator(T numerator){ this->numerator = numerator;}
        void setDenominator(T denominator){ this->denominator = denominator;}

        T getGCD(T a, T b)const;
        T getLCM(T a, T b)const;

        //operator double(void) const {return (double)numerator / denominator;}
        //operator bool(void) const {return this->numerator != 0;}
        
        template<typename U>
        friend std::ostream& operator<<(std::ostream& out, const Fraction<U>& fraction);
        template<typename U>
        friend std::istream& operator>>(std::istream& in, Fraction<U>& fraction);

        template<typename U>
        friend Fraction<U> operator+(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator+(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend Fraction<U> operator+(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend Fraction<U> operator-(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend Fraction<U> operator*(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator*(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend Fraction<U> operator*(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend Fraction<U> operator/(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator/(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend Fraction<U> operator/(const double number, const Fraction<U>& fraction);

        Fraction<T> operator=(const Fraction<T>& fraction);
        Fraction<T> operator=(const double number);
        Fraction<T> operator+=(const Fraction<T>& fraction);
        Fraction<T> operator+=(const double number);
        Fraction<T> operator-=(const Fraction<T>& fraction);
        Fraction<T> operator-=(const double number);
        Fraction<T> operator*=(const Fraction<T>& fraction);
        Fraction<T> operator*=(const double number);
        Fraction<T> operator/=(const Fraction<T>& fraction);
        Fraction<T> operator/=(const double number);

        template<typename U>
        friend bool operator==(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend bool operator==(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend bool operator==(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend bool operator!=(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend bool operator!=(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend bool operator!=(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend bool operator<(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend bool operator<(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend bool operator<(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend bool operator>(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend bool operator>(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend bool operator>(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend bool operator<=(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend bool operator<=(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend bool operator<=(const double number, const Fraction<U>& fraction);

        template<typename U>
        friend bool operator>=(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend bool operator>=(const Fraction<U>& fraction, const double number);
        template<typename U>
        friend bool operator>=(const double numer, const Fraction<U>& fraction);

        template<typename U>
        friend bool operator!(const Fraction<U>& fraction);

        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction);
    };
}