#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;

void dataset1(const string &nombreArchivo, int cantidad) {
    
    ofstream fp;
    fp.open(nombreArchivo);

    if (!fp) {
        cerr << "Error al abrir el archivo!" << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        
        fp << i << endl;
    }
    fp.close();
}

void dataset2(const string &nombreArchivo, int cantidad) {
    
    ofstream fp;
    fp.open(nombreArchivo);

    if (!fp) {
        cerr << "Error al abrir el archivo!" << endl;
        return;
    }

    for (int i = cantidad; i >0; i--) {
        
        fp << i << endl;
    }
    fp.close();
}

void dataset3(const string &nombreArchivo, int cantidad) {
    
    ofstream fp;
    fp.open(nombreArchivo);

    if (!fp) {
        cerr << "Error al abrir el archivo!" << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        int x = rand();
        fp << x << endl;
    }
    fp.close();
}

void dataset4(const string &nombreArchivo, int cantidad) {
    
    ofstream fp;
    fp.open(nombreArchivo);

    if (!fp) {
        cerr << "Error al abrir el archivo!" << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        if(i%3==0 || i%7==0){
            int x = rand();
            fp << x << endl;
        }
        else{
            fp << i << endl;
        }

    }
    fp.close();
}

void dataset5(const string &nombreArchivo, int cantidad) {
    
    ofstream fp;
    fp.open(nombreArchivo);

    if (!fp) {
        cerr << "Error al abrir el archivo!" << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {

        if( i%17==0 || i%32==0){
            int j = i+5;

            while(i < j){
                int x = rand();
                fp << x << endl;    
                i++;            
            }
        }
        else{
            fp << i << endl;
        }

    }
    fp.close();
}

int main() {
    int n = pow(10, 5);  
/*     dataset1("dataset1.txt", n);
    dataset2("dataset2.txt", n); */

    dataset3("dataset3.txt", n);

    /* dataset4("dataset4.txt", n); */

    /* dataset5("dataset5.txt", n); */

    return 0;
}



