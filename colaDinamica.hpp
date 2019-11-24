#include <iostream>

using namespace std;

template <typename T> struct colaDinamica;
template <typename T> void inicializar(colaDinamica<T>& c);
template <typename T> bool esVacia(colaDinamica<T> c);
template <typename T> void anyadir(colaDinamica<T>& c, T elemento);
template <typename T> void mostrar(colaDinamica<T> c);
template <typename T> void eliminar(colaDinamica<T>& c);

template <typename T>
struct colaDinamica {
private:
    struct Nodo{
        T dato;
        Nodo* sig;
    };
    Nodo* primero;
    Nodo* ultimo;
    int numElem;
public:
    friend void inicializar<T>(colaDinamica<T>& c);
    friend bool esVacia<T>(colaDinamica<T> c);
    friend void anyadir<T>(colaDinamica<T>& c, T elemento);
    friend void mostrar<T>(colaDinamica<T> c);
    friend void eliminar<T>(colaDinamica<T>& c);
};

template <typename T>
void inicializar(colaDinamica<T>& c){
    c.numElem=0;
    c.primero=nullptr;
    c.ultimo=nullptr;
}

template <typename T>
bool esVacia(colaDinamica<T> c){
    if(c.numElem==0){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
void anyadir(colaDinamica<T>& c, T elemento){
    if(esVacia(c)){
        typename colaDinamica<T>::Nodo* aux= new typename colaDinamica<T>::Nodo;
        aux->dato=elemento;
        aux->sig=nullptr;
        c.primero= aux;
        c.ultimo= aux;
        aux=nullptr;
        c.numElem++;
    }
    else{
        typename colaDinamica<T>::Nodo* aux= new typename colaDinamica<T>::Nodo;
        aux->dato=elemento;
        aux->sig=nullptr;
        c.ultimo->sig=aux;
        c.ultimo=aux;
        aux=nullptr;
        c.numElem++;
    }
}

template <typename T>
void mostrar(colaDinamica<T> c){
    if(!esVacia(c)){
        typename colaDinamica<T>::Nodo* aux;
        aux=c.primero;
        while(aux->sig!=nullptr){
            cout << aux->dato << endl;
            aux= aux->sig;
        }
        cout << aux->dato << endl;
    }
}

template <typename T>
void eliminar(colaDinamica<T>& c){
    typename colaDinamica<T>::Nodo* aux;
    aux=c.primero;
    c.primero= c.primero->sig;
    delete(aux);
}