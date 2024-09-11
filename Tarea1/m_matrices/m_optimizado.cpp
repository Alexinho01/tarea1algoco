#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

// Función para transponer una matriz
vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

// Función para multiplicar dos matrices usando la transposición
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int j = B[0].size();

    vector<vector<int>> C(n, vector<int>(j, 0));

    // Transponer la matriz B
    vector<vector<int>> B_T = transpose(B);

    // Multiplicación de matrices optimizada
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < j; ++k) {
            for (int l = 0; l < m; ++l) {
                C[i][k] += A[i][l] * B_T[k][l];
            }
        }
    }
    return C;
}
vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo, int& filas, int& columnas) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        exit(1);
    }

    // Leer dimensiones de la matriz
    archivo >> filas >> columnas;

    // Crear la matriz
    vector<vector<int>> matriz(filas, vector<int>(columnas));

    // Leer datos de la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo >> matriz[i][j];
        }
    }

    archivo.close();
    return matriz;
}

int main() {
    int filasA,columnasA,filasB,columnasB;

    vector<vector<int>> A = leerMatrizDesdeArchivo("../dataset_m_matrices/dataset5matrizA.txt", filasA, columnasA);
    vector<vector<int>> B = leerMatrizDesdeArchivo("../dataset_m_matrices/dataset5matrizB.txt", filasB, columnasB);

    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> C = multiplyMatrices(A, B);

    auto end = chrono::high_resolution_clock::now();    
    chrono::duration<double> duration = end - start;

    cout << "Duración: " << duration.count() << " segundos." << endl;

    return 0;
}
