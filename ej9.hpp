#include <iostream>

using namespace std;

struct vectorCuasiVacio{
private:
    struct Nodo{
        int N;
        int valor;
        Nodo* sig;
    };
    Nodo* primero;
    Nodo* ultimo;

public:
    friend void crear(vectorCuasiVacio& v);
    friend void suma(vectorCuasiVacio v1,vectorCuasiVacio v2, vectorCuasiVacio& suma);
    friend void producto(vectorCuasiVacio& v, int escalar);
    friend void producto(vectorCuasiVacio v1,vectorCuasiVacio v2, vectorCuasiVacio& suma);

};

void crear(vectorCuasiVacio& v){
    v.primero=nullptr;
    v.ultimo=nullptr;
}

void suma(vectorCuasiVacio v1,vectorCuasiVacio v2, vectorCuasiVacio& suma){
    vectorCuasiVacio::Nodo* uno= v1.primero;
    vectorCuasiVacio::Nodo* dos= v2.primero;
    vectorCuasiVacio::Nodo* tre= suma.primero;

    while(uno!=nullptr || dos!=nullptr){
        if(uno->N==dos->N){
            tre= new vectorCuasiVacio::Nodo;
            tre->N=uno->N;
            tre->valor=uno->valor+dos->valor;
            tre= tre->sig;
            uno=uno->sig;
            dos=dos->sig;
        }else if(uno->N<dos->N && uno!=nullptr){
            tre= new vectorCuasiVacio::Nodo;
            tre->N=uno->N;
            tre->valor=uno->valor;
            tre=tre->sig;
            uno=uno->sig;
        }else if(uno->N>dos->N && dos!=nullptr){
            tre= new vectorCuasiVacio::Nodo;
            tre->N=dos->N;
            tre->valor=dos->valor;
            tre=tre->sig;
            dos=dos->sig;
        }
    }
    suma.ultimo=tre;
}

void producto(vectorCuasiVacio& v, int escalar){
    vectorCuasiVacio::Nodo* aux= v.primero;
    while(aux!=nullptr){
        aux->valor=aux->valor*escalar;
        aux=aux->sig;
    }
}

void producto(vectorCuasiVacio v1,vectorCuasiVacio v2, vectorCuasiVacio& suma){
    vectorCuasiVacio::Nodo* uno= v1.primero;
    vectorCuasiVacio::Nodo* dos= v2.primero;
    vectorCuasiVacio::Nodo* tre= suma.primero;

    while(uno!=nullptr || dos!=nullptr){
        if(uno->N==dos->N){
            tre= new vectorCuasiVacio::Nodo;
            tre->N=uno->N;
            tre->valor=uno->valor*dos->valor;
            tre= tre->sig;
            uno=uno->sig;
            dos=dos->sig;
        }else if(uno->N<dos->N && uno!=nullptr){
            uno=uno->sig;
        }else if(uno->N>dos->N && dos!=nullptr){
            dos=dos->sig;
        }
    }
    suma.ultimo=tre;
}