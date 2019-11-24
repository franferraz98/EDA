#include <iostream>

using namespace std;

struct listacpdi{
private:
    struct elemento{
        int valor;
        elemento* ant;
        elemento* sig;
    };
    
    elemento* primero;
    elemento* pdi;
public:
    friend void iniciar(listacpdi& l);
    friend void anyadir(listacpdi& l, int valor);
    friend void iniciarpdi(listacpdi& l);
    friend void avanzarpdi(listacpdi& l);
    friend int numElem(listacpdi l);
    friend void eliminar(listacpdi& l, int valor);
    friend void invertir(listacpdi& l);
    friend void concatenar(listacpdi& a, listacpdi b);
};

void iniciar(listacpdi& l){
    l.pdi=nullptr;
    l.primero=nullptr;
}

void anyadir(listacpdi& l, int valor){
    listacpdi::elemento* aux=l.primero;
    while(aux!=nullptr){
        aux=aux->sig;
    }

    aux->sig= new listacpdi::elemento;
    aux->sig->valor=valor;
    aux->sig->sig=nullptr;
    aux->sig->ant=aux;
}

void iniciarpdi(listacpdi& l){
    l.pdi=l.primero;
}

void avanzarpdi(listacpdi& l){
    l.pdi=l.pdi->sig;
}

int numElem(listacpdi l){
    int i=0;
    listacpdi::elemento* aux=l.primero;
    while(aux!=nullptr){
        i++;
        aux=aux->sig;
    }
    return i;
}

void eliminar(listacpdi& l, int valor){
    listacpdi::elemento* aux=l.primero;
    listacpdi::elemento* matar=l.primero;
    while(aux->sig!=nullptr){
        if(aux->valor==valor){
            aux->ant->sig=aux->sig;
            aux->sig->ant=aux->ant;
            matar=aux;
            aux=aux->sig;
            delete(matar);
        }
        aux=aux->sig;
    }
}

void invertir(listacpdi& l){
    listacpdi::elemento* aux=l.primero;
    listacpdi::elemento* permutar;
    while(aux->sig!=nullptr){
        permutar=aux->sig;
        aux->sig=aux->ant;
        aux->ant=permutar;
        aux=aux->ant;
    }
}

void concatenar(listacpdi& a, listacpdi b){
    listacpdi::elemento* aux=a.primero;
    while(aux->sig!=nullptr);
    aux->sig=b.primero;
}