#include "Matrix_.hpp"

template<typename T>
Matrix<T>::Matrix(int rows, int cols, T**data) {
    this->rows = rows;
    this->cols = cols;
    this->data = new T*[rows];
    for(int i = 0; i < rows; ++i)
        this->data[i] = new T[cols]{0};
    
    if(data)
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                this->data[i][j] = data[i][j];
}

template<typename T>
Matrix<T>::~Matrix() {
    for(int i = 0; i < rows; ++i)
        delete this->data[i];
    delete this->data;
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix) {
    for(int i = 0; i < matrix.rows; ++i) {
        for(int j = 0; j < matrix.cols; ++j)
            out << matrix.data[i][j] << "\t";
        out << std::endl;
    }
    return out;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)const {
    if(this->rows != other.rows && this->cols != other.cols) {
        std::cout << "Matrixes have different sizes" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> result(this->rows, this->cols, this->data);
    for(int i = 0; i < this->rows; ++i)
        for(int j = 0; j < this->cols; ++j)
            result.data[i][j] += other.data[i][j];
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other)const {
    if(this->rows != other.rows && this->cols != other.cols) {
        std::cout << "Matrixes have different sizes" << std::endl;
        return Matrix<T>();
    }
    
    Matrix<T> result(this->rows, this->cols, this->data);
    for(int i = 0; i < this->rows; ++i)
        for(int j = 0; j < this->cols; ++j)
            result.data[i][j] -= other.data[i][j];
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)const {
    if(this->cols != other.rows) {
        std::cout << "Matrixes have different sizes" << std::endl;
        return Matrix<T>();
    }
    
    Matrix<T> result(this->rows, other.cols);
    for(int i = 0; i < this->rows; ++i)
        for(int j = 0; j < other.cols; ++j)
            for(int k = 0; k < this->cols; ++k)
                result.data[i][j] += this->data[i][k] * other.data[k][j];
    return result;
}

template<typename U>
Matrix<U> operator*(const U& number, const Matrix<U>& matrix) {
    Matrix<U> result = matrix;
    for(int i = 0; i < matrix.rows; ++i)
        for(int j = 0; j < matrix.cols; ++j)
            result.data[i][j] *= number;
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator^(const int number)const {
    if(this->rows != this->cols) {
        std::cout << "Matrixe have different sizes" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> result(*this);
    for(int i = 0; i < number - 1; ++i)
        result = (result * *this);
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& other) {
    this->rows = other.rows;
    this->cols = other.cols;
    for(int i = 0; i < this->rows; ++i)
        for(int j = 0; j < this->cols; ++j)
            this->data[i][j] = other.data[i][j];
    return *this;
}