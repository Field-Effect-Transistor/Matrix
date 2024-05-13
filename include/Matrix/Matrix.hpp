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
        }
    
    };
}