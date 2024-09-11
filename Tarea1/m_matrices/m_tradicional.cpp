#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

// Función para multiplicar dos matrices A (n x m) y B (m x j)
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int j = B[0].size();

    // Inicializar la matriz resultante C (n x j) con ceros
    vector<vector<int>> C(n, vector<int>(j, 0));

    // Multiplicación de matrices
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < j; k++) {
            for (int l = 0; l < m; l++) {
                C[i][k] += A[i][l] * B[l][k];
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
    vector<vector<int>> C = multiplicarMatrices(A, B); 
    auto end = chrono::high_resolution_clock::now();    
    chrono::duration<double> duration = end - start;

    cout << "Duración: " << duration.count() << " segundos." << endl;

    return 0;
}



