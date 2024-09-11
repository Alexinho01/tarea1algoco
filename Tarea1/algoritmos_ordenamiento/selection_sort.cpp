#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){

    ifstream inputFile("../dataset_ordenamiento/dataset5.txt"); // Abrir el archivo en modo de lectura
    vector<int> numeros;               // Vector para almacenar los enteros

    if (!inputFile) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    int numero;
    while (inputFile >> numero) {      // Leer cada número del archivo
        numeros.push_back(numero);     // Guardar el número en el vector
    }

    inputFile.close();

    cout<< "El vector tiene "<<numeros.size()<<" elementos."<<endl;

    auto start = chrono::high_resolution_clock::now();

    for(int j = 0 ;j < numeros.size()-1 ;j++){ //posicion en el arreglo 

        int imin = j;   //definimos el elemento minimo

        for(int i = j+1; i < numeros.size() ;i++){ // for que recorre el arreglo y busca el menor elemento

            if(numeros[i]<numeros[imin]) //verifica el menor elemento en el arreglo
                imin = i; //si el elemento es el menor guarda el elemento

        }

        if(imin != j) //si la posicion del elemento menor es distinta a la posicion actual
            swap(numeros[j],numeros[imin]);//intercambia el elemento

    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
 
    cout<<endl;
    cout << "El data set 1: ";
    cout << "Duración: " << duration.count() << " segundos." << endl;

    return 0;
}