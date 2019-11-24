#include <iostream>

using namespace std;

struct competicion{
private:
    struct participante{
        int dorsal;
        double tiempo;
        participante* siguiente;
        participante* anterior;
    };

    participante* primero;
public:
    friend void iniciar(competicion& c);
    friend void registrar(competicion& c, int participante, double tiempo);
    friend void descalificar(competicion& c, int dorsal);
    friend int ganador(competicion c);
    friend double tiempo(competicion c, int dorsal);
};

void iniciar(competicion& c){
    c.primero=nullptr;
}

void registrar(competicion& c, int participante, double tiempo){
    if(c.primero==nullptr){
        competicion::participante* nuevo= new competicion::participante;
        nuevo->dorsal=participante;
        nuevo->tiempo=tiempo;
        nuevo->siguiente=nullptr;
        nuevo->anterior=nullptr;
        c.primero=nuevo;
    }else{
        competicion::participante* nuevo=c.primero;
        while(nuevo->dorsal<participante && nuevo->siguiente!=nullptr){
            nuevo= nuevo->siguiente;
        }
        if(nuevo->dorsal==participante){
            if(nuevo->tiempo<tiempo){
                nuevo->tiempo=tiempo;
            }
        }else if(nuevo->siguiente==nullptr){
            nuevo->siguiente= new competicion::participante;
            nuevo->siguiente->dorsal=participante;
            nuevo->siguiente->anterior=nuevo;
            nuevo->siguiente->tiempo=tiempo;
            nuevo->siguiente->siguiente=nullptr;
        }else{
            nuevo=nuevo->anterior;
            competicion::participante* aux= new competicion::participante;
            aux->anterior=nuevo;
            aux->dorsal=participante;
            aux->tiempo=tiempo;
            aux->siguiente=nuevo->siguiente;
            nuevo->siguiente->anterior=aux;
            nuevo->siguiente=aux;
        }
        
    }
}

void descalificar(competicion& c, int dorsal){
    competicion::participante* aux=c.primero;
    while(aux->dorsal!=dorsal && aux!=nullptr);
    if(aux->dorsal==dorsal){
        aux->siguiente->anterior=aux->anterior;
        aux->anterior->siguiente=aux->siguiente;
        delete(aux);
    }
}

int ganador(competicion c){
    competicion::participante* aux=c.primero;
    competicion::participante* mejor=c.primero;
    while(aux!=nullptr){
        if(aux->tiempo<mejor->tiempo){
            mejor=aux;
        }
    }

    return mejor->dorsal;
}

double tiempo(competicion c, int dorsal){
    competicion::participante* aux=c.primero;
    while(aux->dorsal!=dorsal && aux!=nullptr);

    if(aux->dorsal==dorsal){
        return aux->tiempo;
    }else{
        return -1.0;
    }
}
