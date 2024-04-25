#include "Matrix_.hpp"

template<typename T>
Matrix<T>::Matrix(int rows, int cols, T**data) {
    this->rows = rows;
    this->cols = cols;
    this->data = new T*[rows];
    for(int i = 0; i < rows; ++i)
        this->data[i] = new T[cols];
    
    if(data)
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                this->data[i][j] = data[i][j];
    else 
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                this->data[i][j] = 0;

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
    if(number != 0)
        return Matrix<U>(matrix.rows, matrix.cols); 

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

template<typename T>
Matrix<T> Matrix<T>::getTranspose() const {
    Matrix<T> result(this->cols, this->rows);
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            result[j][i] = this->data[i][j];
    return result;
}

template<typename T>
T Matrix<T>::getDeterminant() const {
    if(this->rows != this->cols) {
        std::cout << "Matrixe have different sizes" << std::endl;
        return 0;
    }

    if(this->rows == 1)
        return **(this->data);

    if(this->rows == 2)
        return (this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0]);

    T result = 0;
    for(int i = 0; i < this->cols; ++i)
        result += this->data[0][i] * this->getAlgebraicComplement(0, i);

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::getSubMatrix(int upperRow, int lowerRow, int leftCol, int rightCol) const {
    if(upperRow < 0 || upperRow > this->rows){
        std::cout << "Upper row index is out of bounds" << std::endl;
        return Matrix<T>();
    }

    if(lowerRow < 0 || lowerRow > this->rows){
        std::cout << "Lower row index is out of bounds" << std::endl;
        return Matrix<T>();
    }

    if(leftCol < 0 || leftCol > this->cols){
        std::cout << "Left column index is out of bounds" << std::endl;
        return Matrix<T>();
    }

    if(rightCol < 0 || rightCol > this->cols){
        std::cout << "Right column index is out of bounds" << std::endl;
        return Matrix<T>();
    }

    if(rightCol < leftCol || lowerRow < upperRow){
        std::cout << "Wrong indexes" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> result(lowerRow - upperRow + 1, rightCol - leftCol + 1);
    for(int i = 0; i < result.rows; ++i)
        for(int j = 0; j < result.cols; ++j)
            result.data[i][j] = this->data[upperRow + i][leftCol + j];

    return result;
};

template<typename T>
Matrix<T> Matrix<T>::removeRowCol(int row, int col) const {
    if(row < 0 || row >= this->rows){
        std::cout << "Row index is out of bounds" << std::endl;
        return Matrix<T>(*this);
    }
    if(col < 0 || col >= this->cols){
        std::cout << "Col index is out of bounds" << std::endl;
        return Matrix<T>(*this);
    }
    Matrix<T> result = Matrix<T>(this->rows - 1, this->cols - 1);
    for(int resRow = 0, i = 0; i < this->rows; ++i)
        if(i != row){
            for(int resCol = 0, j = 0; j < this->cols; ++j)
                if(j != col)
                    result[resRow][resCol++] = this->data[i][j];
            ++resRow;
        }

    return result;
}

template<typename T>
T Matrix<T>::getAlgebraicComplement(int row, int col) const {
    if((row < 0 || row >= this->rows) || (col < 0 || col >= this->cols)){
        std::cout << "Wrong indexes" << std::endl;
        return 0;
    }
    if((col + row) % 2)
        return -1 * (this->removeRowCol(row, col)).getDeterminant();

    return (this->removeRowCol(row, col)).getDeterminant();
}

template<typename T>
Matrix<T> Matrix<T>::getInverse() const {
    if(this->getDeterminant() == 0){
        std::cout << "Matrix have no inverse" << std::endl;
        return Matrix<T>();
    }
    return this->getAdjoint() / this->getDeterminant();
}

template<typename T>
Matrix<T> Matrix<T>::getAdjoint() const {
    Matrix<T> result(this->rows, this->cols);
    for(int i = 0; i < this->rows; ++i)
        for(int j = 0; j < this->cols; ++j)
            result.data[i][j] = this->getAlgebraicComplement(j, i);
    return result;
}

template<typename U>
Matrix<U> operator*=(const Matrix<U>& matrix, const U& number) {
    return number = number * matrix;
}

template<typename U>
Matrix<U> operator*=(const U& number, const Matrix<U>& matrix) {
    return number = number * matrix;
}

template<typename U>
Matrix<U> operator*(const Matrix<U>& matrix, const U& number) {
    return number * matrix;
};

template<typename T>
Matrix<T>  Matrix<T>::operator^=(const int number){
    return *this = *this ^ number;
};

template<typename T>
Matrix<T> Matrix<T>::operator/=(const T& number){
    return *this = *this / number;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& number)const {
    Matrix<T> result(*this);
    if(number == 0){
        std::cout << "Division by zero" << std::endl;
    } else {
        for(int i = 0; i < this->rows; ++i)
            for(int j = 0; j < this->cols; ++j)
                result.data[i][j] /= number;
    }
    return result;
};

template<typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T>& other){
    return *this = *this * other;
}

template<typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T>& other) {
    return *this = *this - other;
}

template<typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& other) {
    return *this = *this + other;
}

template<typename T>
T* Matrix<T>::operator[](int row){
    return data[row];
}

template<typename T>
T* Matrix<T>::get(int row, int col) {
    return *data[row][col];
}
template<typename T>
T** Matrix<T>::getData() {
    return data;
}
template<typename T>
int Matrix<T>::getRows() {
    return rows;
}
template<typename T>
int Matrix<T>::getCols() {
    return cols;
}