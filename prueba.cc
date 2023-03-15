#include<iostream>
#include <cmath>
using namespace std;


//El valor del nodo hoja es a partir igual de: 2^(p-1)

// La secuencia se repite cada : 2^p - (2^p)/2  

//Los valores de esa profundidad son: 2^p-1 < valores < 2^p




int recursiva(int p,int bola){
    if (p == 1){
        return 1;
    }else{
        //Parte derecha
        if(bola > ((pow(2, p)) - (pow(2, p) / 2))){
            return 2*recursiva(p-1,bola) + 1;
        }else{
            return 2* recursiva(p-1,bola);
        }
    }
}



int main(){
    for(int i =1;i<8;i++){
        cout << "Bola " << i << " en la pos: " << recursiva(4,i) << endl;
    }

}