#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <execution>
using namespace std;

int main(){

    ifstream inputFile("../dataset_ordenamiento/dataset5.txt");
    vector<int> numeros;              

    if (!inputFile) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    int numero;
    while (inputFile >> numero) {     
        numeros.push_back(numero);   
    }

    inputFile.close();

    auto start = chrono::high_resolution_clock::now();

    sort(numeros.begin(), numeros.end());//ayuda aqui!

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Duración: " << duration.count() << " segundos." << endl; 
    return 0;
}