#include <iostream>

using namespace std;

struct listaJ{
private:
    struct elemento{
        int valor;
        elemento* ant;
        elemento* sig;
    };
    
    elemento* primero;
    elemento* ultimo;
public:
    friend void crear(listaJ& l);
    friend void anyadir(listaJ& l , int elem);
    friend void josefo(listaJ& l, int veces);
};

void crear(listaJ& l){
    l.primero=nullptr;
}

void anyadir(listaJ& l , int elem){
    if(l.primero==nullptr){
        l.primero= new listaJ::elemento;
        l.primero->valor=elem;
        l.primero->sig=nullptr;
        l.primero->ant=nullptr;
        l.ultimo=l.primero;
    }else{
        listaJ::elemento* nuevo= new listaJ::elemento;
        nuevo->ant=l.ultimo;
        nuevo->sig=l.primero;
        nuevo->valor=elem;
        l.primero->ant=nuevo;
        l.ultimo->sig=nuevo;
        l.ultimo=nuevo;
    }
}

void josefo(listaJ& l, int veces){
    listaJ::elemento* pelota=l.primero;
    for(int i=0; i<=pelota->valor; i++){
        pelota=pelota->sig;
    }

    pelota->ant->sig=pelota->sig;
    pelota->sig->ant=pelota->ant;
    delete(pelota);
}

