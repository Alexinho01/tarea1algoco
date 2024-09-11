#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generarMatriz(const string &nombreArchivo, int filas, int columnas) {
    ofstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error al abrir el archivo!" << endl;
        return;
    }

    archivo << filas <<" "<<columnas<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int valor = rand() ; 
            archivo << valor;
            if (j < columnas - 1) {
                archivo << " ";
            }
        }
        archivo << endl;
    }
    archivo.close();
}

void generarMatriz1(const string &nombreArchivo, int filas, int columnas) {
    ofstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error al abrir el archivo!" << endl;
        return;
    }

    archivo << filas <<" "<<columnas<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if(i % 13 == 0 || j%7==0){
                archivo << 0;
            }
            else{
                int valor = rand(); // Genera un número aleatorio entre 0 y 99
                archivo << valor;                
            }
            if (j < columnas - 1) {
                archivo << " ";
            }
        }
        archivo << endl;
    }
    archivo.close();
}

int main() {
    int n, m, j;
    n=2048;
    m=2048;
    j=2048;

    generarMatriz("dataset5matrizA.txt", n, m);
    generarMatriz("dataset5matrizB.txt", m, j);

    cout << "Matrices generadas y guardadas en 'matrizA.txt' y 'matrizB.txt'." << endl;

    return 0;
}

