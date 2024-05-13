#include <iostream>
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

        }
        Matrix(): Matrix(1, 1) {}
        Matrix(const Matrix<T>& parent) {
            rows_ = parent.rows_;
            columns_ = parent.columns_;
            data_ = new T*[rows_];
            for(size_t i = 0; i < rows_; i++)
                data_[i] = new T[columns_];
            for(size_t i = 0; i < rows_; i++)
                for(size_t j = 0; j < columns_; j++)
                    data_[i][j] = parent.data_[i][j];
        }

    // Destructor
        ~Matrix() {
            for(size_t i = 0; i < rows_; i++)
                delete[] data_[i];
            delete[] data_;
            std::cout << "Imma work!" << std::endl;
        }
    
    // Getters
        inline T** getData(void) const {return data_;}
        inline size_t getRows(void) const {return rows_;}
        inline size_t getColumns(void) const {return columns_;}

    // Operators
        inline T* operator[](size_t row) {return data_[row];}
        std::istream friend operator>>(std::istream in, Matrix<T>& matrix){
            return in;
        }
        std::ostream& friend operator<<(std::ostream& out, Matrix<T>& matrix) {
            for(size_t i = 0; i < matrix.getRows(); ++i) {
                for(size_t j = 0; j < matrix.getColumns(); ++j)
                    out << matrix[i][j] << "\t";
                out << std::endl;
            }
            return out;
        }

    // Matrix x Matrix
        Matrix<T> friend operator+(const Matrix<T>& left, const Matrix<T>& right) {
            if(left.getRows() == right.getRows() && left.getColumns() == right.getColumns()) {
                std::cerr << "Uncompletible matrixes\n";
                return Matrix<T>();
            }

            Matrix<T> result(left);
            for(size_t i = 0; i < result.getRows(); ++i)
                for(size_t j = 0; j < result.getColumns(); ++j)
                    result[i][j] += left[i][j];
                
            return result;
        }

    // Matrix x number
        Matrix<T> friend operator*(const T& number, const Matrix<T>& matrix) {
            Matrix<T> result(matrix);
            for(size_t i = 0; i < result.rows_; i++)
                for(size_t j = 0; j < result.columns_; j++)
                    result.data_[i][j] *= number;
            return result;
        }
        Matrix<T> operator*(const T& number) {
            return number * *this;
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