#include <iostream>

template <typename T>
class Matrix{
private:
    T**data;
    int rows, cols;
public:
    Matrix(int rows, int cols, T** data = nullptr);
    Matrix():Matrix(1, 1){};
    Matrix(const Matrix& parent):Matrix(parent.rows, parent.cols, parent.data){};
    ~Matrix();

    T* get(int row, int col);
    T** getData();
    int getRows();
    int getCols();

    T getAlgebraicComplement(int row, int col) const;
    T getDeterminant() const;
    Matrix getTranspose() const;
    Matrix getAdjoint() const;
    Matrix getInverse() const;
    Matrix getSubMatrix(int upperRow, int lowerRow, int leftCol, int rightCol) const;
    Matrix removeRowCol(int row, int col) const;

    T* operator[](int row);
    Matrix<T> operator+(const Matrix<T>& other)const;
    Matrix operator+=(const Matrix<T>& other);
    Matrix operator-(const Matrix& other)const;
    Matrix operator-=(const Matrix& other);
    Matrix operator*(const Matrix& other)const;
    Matrix operator*=(const Matrix& other);
    Matrix operator/(const T& number)const;
    Matrix operator/=(const T& number);
    Matrix operator=(const Matrix& other);
    /** @brief Matrix power */
    Matrix operator^(const int number)const;
    Matrix operator^=(const int number);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
    template<typename U>
    friend std::istream& operator>>(std::istream& in, Matrix<U>& matrix);

    template<typename U>
    friend Matrix<U> operator*(const U& number, const Matrix<U>& matrix);
    template<typename U>
    friend Matrix<U> operator*=(const U& number, const Matrix<U>& matrix);
    template<typename U>
    friend Matrix<U> operator*(const Matrix<U>& matrix, const U& number);
    template<typename U>
    friend Matrix<U> operator*=(const Matrix<U>& matrix, const U& number);
};