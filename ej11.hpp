#include <iostream>

using namespace std;

template <typename T> struct matrizCuasiVacia;
template <typename T> void crear(matrizCuasiVacia<T>& v);
template <typename T> void anyadir(matrizCuasiVacia<T>& m, T n);


template <typename T>
struct matrizCuasiVacia{
private:
    struct Nodo{
        T valor;
        int N;
        int M;
        Nodo* sig;
    };
    Nodo* primero;
    Nodo* ultimo;
    int alto;
    int ancho;
public:
    friend void crear<T>(matrizCuasiVacia& v);
    friend void anyadir<T>(matrizCuasiVacia& m, T n);
};