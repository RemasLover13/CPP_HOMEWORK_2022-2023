#include <iostream> // cout, cin
#include <fstream> // ifstream, ofstream

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **matrix;
public:
    Matrix() {
        cols = 0;
        rows = 0;
        matrix = nullptr;
    }

    Matrix(int rows, int cols, int **matrix) {
        this->rows = rows;
        this->cols = cols;
        this->matrix = matrix;

    }

    Matrix(const Matrix &other_matrix) {
        this->rows = other_matrix.rows;
        this->cols = other_matrix.cols;
        this->matrix = new int *[other_matrix.rows];

        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }

        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                this->matrix[i][j] = other_matrix.matrix[i][j];
            }
        }

    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    Matrix &operator*(int number) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] *= number;
            }
        }
    }

    void transposition() {
        int** temp = new int*[rows];
        for (int i = 0; i < rows; i++) {
            temp[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = temp[j][i];
            }

        }

        for (int i = 0; i < rows; i++) {
            delete[] temp;
        }

        delete[] temp;


    }

    Matrix operator+(Matrix &other_matrix) {

        if (this->rows != other_matrix.rows && this->cols != other_matrix.cols) {
            cout << "Matrices must be the same size!" << endl;
        } else {
            Matrix temp(*this);
            for (int i = 0; i < rows; i++) {    // [0]1 [0]2   [0] 5 [0]6
                for (int j = 0; j < cols; j++) {// [0]3 [0]4  + [0]7 [0]8
                    temp.matrix[i][j] += other_matrix.matrix[i][j];
                }
            }
            return temp;
        }


    }

    Matrix operator*(Matrix &other_matrix) {
        if (this->cols != other_matrix.rows) {
            cout << "the number of columns of matrix A is equal to the number of rows of matrix B" << endl;
        } else {
            Matrix temp(*this);
            // a1 a2   c1 c2   (a1*c1 + a2*d1)  (a1*c2 + a2*d2)
            // b1 b2 * d1 d2 = (b1*c1 + b2*d1) (b1*c2 + b2*d2)
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    temp.matrix[i][j] = 0;
                    for (int k = 0; k < cols; k++) {
                        temp.matrix[i][j] += this->matrix[i][k] * other_matrix.matrix[k][j];
                    }
                }
            }
            return temp;
        }
    }


    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }


};


int main() {
//    Реализуйте следующие операции:
//    1. Вывод матрицы на экран.
//    2. Умножение матрицы на число (скалярное значение).
//    3. Умножение двух матриц, если это возможно (цикл в цикле в цикле ...).
//    4. Сложение двух матриц, если это возможно.
//    5. Транспонирование матрицы

    ifstream in("../matrices.txt");

    int rows;
    int cols;
    int value;

    in >> rows >> cols;
    //memory alocation
    int **left_matrix = new int *[rows]{};
    // &left_matrix + 0
    for (int i = 0; i < rows; i++) {
        left_matrix[i] = new int[cols]{};
    }
    //1. read matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            in >> value;
            left_matrix[i][j] = value;
        }
    }

    Matrix matrix1(rows, cols, left_matrix);
    in >> rows >> cols;
    int **right_matrix = new int *[rows];

    for (int i = 0; i < rows; i++) {
        right_matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            in >> value;
            right_matrix[i][j] = value;
        }
    }
    Matrix matrix2(rows, cols, right_matrix);
    // Display matrices on screen
    matrix1.printMatrix();
    cout << endl;
    matrix2.printMatrix();
    // Matrix addiction
    Matrix matrix3 = matrix1 + matrix2;
    // Matrix multiply
    Matrix matrix4 = matrix1 * matrix2;






    for (int i = 0; i < rows; i++) {
        delete[] left_matrix[i];
    }
    for (int i = 0; i < rows; i++) {
        delete[] right_matrix[i];
    }

    delete[] left_matrix;
    delete[] right_matrix;

    in.close();


    return 0;
}