#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int** Matrix(const int& n, const int& m) {
    int** matrix = new int*[n];

    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    return matrix;
}

void loadMatrixRow(int matrixRow[], const int& m) {
    for (int i = 0; i < m; ++i) {
        cin >> matrixRow[i];
    }
}

void loadMatrix(int* matrix[], const int& n, const int& m) {
    for (int i = 0; i < n; ++i) {
        loadMatrixRow(matrix[i], m);
    }
}

int** transposeMatrix(int* matrix[], const int& n, const int& m) {
    int** transposedMatrix = Matrix(m, n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    return transposedMatrix;
}

void printMatrixRow(const int matrixRow[], const int& m) {
    for (int i = 0; i < m; ++i) {
        cout << matrixRow[i] << " ";
    }
}

void printMatrix(int* matrix[], const int& n, const int& m) {
    for (int i = 0; i < n; ++i) {
        printMatrixRow(matrix[i], m);
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int** matrix = Matrix(n, m);

    loadMatrix(matrix, n, m);

    int** transposedMatrix = transposeMatrix(matrix, n, m);

    printMatrix(transposedMatrix, m, n);

    return 0;
}