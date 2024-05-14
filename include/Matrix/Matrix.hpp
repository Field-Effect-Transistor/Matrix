#include <iostream>
#include <vector>
#pragma once

namespace Matrix {
    template <typename T>
    class Matrix {
    protected:
        size_t rows_;
        size_t columns_;
        T** data_;
    public:
    // Constructors
        Matrix(size_t rows, size_t columns, T** data = nullptr) {
            if(rows > 0)
                rows_ = rows;
            else {
                rows_ = 1;
                std::cerr << "Invalid number of rows. Setting to 1." << std::endl;
            }

            if(columns > 0)
                columns_ = columns;
            else {
                columns_ = 1;
                std::cerr << "Invalid number of columns. Setting to 1." << std::endl;
            }
            
            data_ = new T*[rows_];
            for(size_t i = 0; i < rows_; i++)
                data_[i] = new T[columns_];

            if(data != nullptr) {
                for(size_t i = 0; i < rows_; i++)
                    for(size_t j = 0; j < columns_; j++)
                        data_[i][j] = data[i][j];
            } else {
                for(size_t i = 0; i < rows_; i++)
                    for(size_t j = 0; j < columns_; j++)
                        data_[i][j] = 0;
            }
            std::cout << "Matrix(size_t rows, size_t columns, T** data = nullptr) WORKS" << std::endl;
        }
        Matrix(): Matrix(1, 1) { std::cout << "WITH Matrix(): Matrix(1, 1)" << std::endl;}
        Matrix(const Matrix<T>& parent) {
            rows_ = parent.rows_;
            columns_ = parent.columns_;
            data_ = new T*[rows_];
            for(size_t i = 0; i < rows_; i++)
                data_[i] = new T[columns_];
            for(size_t i = 0; i < rows_; i++)
                for(size_t j = 0; j < columns_; j++)
                    data_[i][j] = parent.data_[i][j];
            std::cout << "Matrix(const Matrix<T>& parent) WORKS" << std::endl;
        }
        explicit Matrix(const std::vector<T>& parent) {
            rows_ = parent.size();
            columns_ = 1;
            data_ = new T*[rows_];
            for(size_t i = 0; i < rows_; i++)
                data_[i] = new T[columns_];
            for(size_t i = 0; i < rows_; i++)
                data_[i][0] = parent[i];
            std::cout << "explicit Matrix(const std::vector<T>& parent) WORKS" << std::endl;
        }
    // Destructor
        ~Matrix() {
            for(size_t i = 0; i < rows_; i++)
                delete[] data_[i];
            delete[] data_;
            std::cout << "~Matrix() WORKS" << std::endl;
        }
    
    // Getters
        inline T** getData(void) const {return data_;}
        inline size_t getRows(void) const {return rows_;}
        inline size_t getColumns(void) const {return columns_;}

    // Methods
        Matrix<T> Transpose(void) const;
        T Determinant(void) const;
        size_t Rank(void) const;
        Matrix<T> RowEchelonForm(void) const;
        Matrix<T> Diagonal(void) const;
        Matrix<T> Inverse(void) const;

    // Operators
        inline T* operator[](size_t row) const {return data_[row];}
        friend std::istream operator>>(std::istream in, Matrix<T>& matrix){
            return in;
        }
        friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
            for(size_t i = 0; i < matrix.getRows(); ++i) {
                for(size_t j = 0; j < matrix.getColumns(); ++j)
                    out << matrix[i][j] << "\t";
                out << std::endl;
            }
            return out;
        }

    // = operators
        const Matrix<T>& operator=(const Matrix<T>& parent) {
            for(size_t i = 0; i < rows_; ++i)
                delete[] data_[i];
            delete[] data_;

            rows_ = parent.rows_;
            columns_ = parent.columns_;

            data_ = new T*[rows_];
            for(size_t i = 0; i < rows_; ++i)
                data_[i] = new T[columns_];

            for(size_t i = 0; i < rows_; ++i)
                for(size_t j = 0; j < columns_; ++j)
                    data_[i][j] = parent.data_[i][j];
            return *this;
        }

    // Matrix x Matrix
        friend Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right) {
            if(left.getRows() != right.getRows() || left.getColumns() != right.getColumns()) {
                std::cerr << "Incompatible matrixes\n";
                return Matrix<T>();
            }

            Matrix<T> result(left);
            for(size_t i = 0; i < result.getRows(); ++i)
                for(size_t j = 0; j < result.getColumns(); ++j)
                    result[i][j] += left[i][j];
                
            return result;
        }
        friend Matrix<T> operator-(const Matrix<T>& left, const Matrix<T>& right) {
            if(left.getRows() == right.getRows() && left.getColumns() == right.getColumns()) {
                std::cerr << "Incompatible matrixes\n";
                return Matrix<T>();
            }

            Matrix<T> result(left);
            for(size_t i = 0; i < result.getRows(); ++i)
                for(size_t j = 0; j < result.getColumns(); ++j)
                    result[i][j] -= left[i][j];
                
            return result;
        }
        friend Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right) {
            if(left.getColumns() != right.getRows()) {
                std::cerr << "Incompatible matrixes\n";
                return Matrix<T>();
            }

            Matrix<T> result(left.getRows(), right.getColumns());
            for(size_t i = 0; i < result.getRows(); ++i)
                for(size_t j = 0; j < result.getColumns(); ++j)
                    for(size_t k = 0; k < left.getColumns(); ++k)
                        result[i][j] += left[i][k] * right[k][j];
            return result;
        }
    // Matrix x number
        friend Matrix<T> operator*(const T& number, const Matrix<T>& matrix) {
            Matrix<T> result(matrix);
            for(size_t i = 0; i < result.rows_; i++)
                for(size_t j = 0; j < result.columns_; j++)
                    result.data_[i][j] *= number;
            return result;
        }
        Matrix<T> operator*(const T& number) {
            return number * *this;
        }
        //refactor to remove operator* 
        friend Matrix<T> operator^(const Matrix<T>& matrix, int power) {
            Matrix<T> result(matrix);
            for(;power > 1; --power)
                result = result * matrix;
            return result;
        }
        Matrix<T> operator/(const T& number) {
            if(number == 0) {
                std::cerr << "Divide by zero";
                return *this;
            }

            Matrix<T> result(*this);
            for(size_t i = 0; i < result.rows_; ++i)
                for(size_t j = 0; j < result.columns_; ++j)
                    result[i][j] /= number;
            return result;
        }
        
    };
}