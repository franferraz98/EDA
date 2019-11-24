#include "ej11.hpp"

using namespace std;

template <typename T>
void crear(matrizCuasiVacia<T>& v){
    v.primero=nullptr;
    v.ultimo=nullptr;
}

template <typename T>
void anyadir(matrizCuasiVacia<T>& m, T n){
    typename matrizCuasiVacia<T>::Nodo* aux= m.primero;
    typename matrizCuasiVacia<T>::Nodo* padre= m.primero;
    while(aux->valor<n && aux!=nullptr){
        padre=aux;
        aux=aux->sig;
    }
}