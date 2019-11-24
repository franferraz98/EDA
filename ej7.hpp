#include <iostream>

using namespace std;

struct lista{
private:
    struct elemento{
        int valor;
        elemento* sig;
    };
    
    elemento* primero;
public:
    friend void crear(lista& l);
    friend void anyadir(lista& l , int elem);
    friend void borrarRepeticiones(lista& l);
};

void crear(lista& l){
    l.primero=nullptr;
}

void anyadir(lista& l, int elem){
    lista::elemento* aux;
    aux=l.primero;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    aux->sig= new lista::elemento;
    aux->sig->valor=elem;
    aux->sig->sig=nullptr;
}

void borrarRepeticiones(lista& l){
    lista::elemento* aux1= l.primero;
    lista::elemento* aux2= l.primero->sig;
    lista::elemento* aux3= l.primero;
    while(aux1!=nullptr){
        while(aux2!=nullptr){
            if(aux1->valor==aux2->valor){
                aux3->sig=aux2->sig;
                delete(aux2);
                aux2=aux3->sig;
            }
            aux2=aux2->sig;
            aux3=aux3->sig;
        }
        aux1=aux1->sig;
        aux2=aux1->sig;
        aux3=aux1;
    }
}