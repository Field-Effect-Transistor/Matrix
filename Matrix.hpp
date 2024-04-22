#include <iostream>

template <typename T>
class Matrix{
private:
    T**data;
    int rows, cols;
public:
    Matrix();
    Matrix(int rows, int cols, T**data);
    Matrix(int rows, int cols);
    Matrix(const Matrix& parent);
    ~Matrix();

    T* get(int row, int col);
    T getDeterminant();
    Matrix getTranspose();
    Matrix getInverse();

    T* operator[](int row);
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix operator/(const Matrix& other);
    Matrix operator/(const T& number);

template<typename U>
friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
template<typename U>
friend std::istream& operator>>(std::istream& in, Matrix<U>& matrix);

template<typename U>
friend Matrix<U> operator*(const U& number, const Matrix<U>& matrix);
template<typename U>
friend Matrix<U> operator*(const Matrix<U>& matrix, const U& number);

};