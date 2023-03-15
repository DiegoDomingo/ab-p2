#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int recursiva(int p,int bola){
    if (p == 1){
        return 1;
    }else{
        //Parte derecha
        if(bola % (2^p - (2^p)/2) == 0){
            return 2*recursiva(p-1,bola) + 1;
        }else{
            return 2* recursiva(p-1,bola);
        }
    }
}

int busquedaInm(int p, int i, int nodo) {
    if (p == 1) {
        return nodo;
    }
    else {
        if (i % 2 != 0) {
            return busquedaInm(p-1, ceil(i / 2.0), nodo * 2);
        }
        else {
            return busquedaInm(p-1, ceil(i / 2.0), nodo * 2 + 1);
        }
    }
}

int busqueda(int p, int i) {
    return busquedaInm(p, i, 1);
}

int main(int argc, char* argv[]) {
    int p, n;
    ifstream f;
    f.open(argv[1]);
    if (f.is_open()) {
        ofstream g;
        g.open(argv[2]);
        if (g.is_open()) {
            while (!f.eof()) {
                f >> p >> n;
                if (n > pow(2, p-1)) {
                    g << "Prueba inválida, n mayor que número de hojas" << endl;
                }
                else {
                    g << "Búsqueda con p = " << p << " y n = " << n << endl;
                    for (int i = 1; i <= n; i++) {
                        g << "Bola " << i << " -> " << busqueda(p, i) << endl;
                    }
                    g << endl;
                }
            }
        }
        g.close();
    }
    f.close();
}
