#include <iostream>

using namespace std;

struct matrizCuasiVacia{
private:
    struct Nodo{
        int valor;
        int N;
        int M;
        Nodo* sig;
    };
    Nodo* primero;
    Nodo* ultimo;
    int alto;
    int ancho;
public:
    friend void crear(matrizCuasiVacia& v);
    friend void anyadir(matrizCuasiVacia& m, int n);
};

void crear(matrizCuasiVacia& v){
    v.primero=nullptr;
    v.ultimo=nullptr;
}

void anyadir(matrizCuasiVacia& m, int n){
    matrizCuasiVacia::Nodo* aux= m.primero;
    matrizCuasiVacia::Nodo* padre= m.primero;
    while(aux->valor<n && aux!=nullptr){
        padre=aux;
        aux=aux->sig;
    }
    
}