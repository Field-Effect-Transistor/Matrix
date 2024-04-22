#include <iostream>

template <typename T>
class Matrix{
private:
    T**data;
    int rows, cols;
public:
    Matrix(int rows, int cols, T** data = nullptr);
    Matrix():Matrix(0, 0){};
    Matrix(const Matrix& parent):Matrix(parent.rows, parent.cols, parent.data){};
    ~Matrix();

    T* get(int row, int col){return *data[row][col];}
    T** getData(){return data;}
    int getRows(){return rows;}
    int getCols(){return cols;}


    T getAlgebraicComplement(int row, int col) const;
    T getDeterminant() const;
    Matrix getTranspose() const;
    Matrix getInverse() const;
    Matrix getSubMatrix(int upperRow, int lowerRow, int leftCol, int rightCol) const;
    Matrix removeRowCol(int row, int col) const;

    T* operator[](int row){return data[row];}
    Matrix<T> operator+(const Matrix<T>& other)const;
    Matrix operator-(const Matrix& other)const;
    Matrix operator*(const Matrix& other)const;
    Matrix operator/(const Matrix& other)const;
    Matrix operator/(const T& number)const {return (1 / number) * number;};
    Matrix operator=(const Matrix& other);
    /** @brief Matrix power */
    Matrix operator^(const int number)const;

template<typename U>
friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
template<typename U>
friend std::istream& operator>>(std::istream& in, Matrix<U>& matrix);

template<typename U>
friend Matrix<U> operator*(const U& number, const Matrix<U>& matrix);
template<typename U>
friend Matrix<U> operator*(const Matrix<U>& matrix, const U& number) { return number * matrix; };
};