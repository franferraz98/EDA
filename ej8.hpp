#include <iostream>

using namespace std;

struct listaAnillos{
private:
    struct nodoAnillo{
        struct nodoNat{
            int valor;
            nodoNat* sig;
        };
        int valor;
        nodoAnillo* sig;
        nodoNat* hijo;
    };

    nodoAnillo* primero;
    nodoAnillo* ultimo;
public:
    friend void borrar(listaAnillos& l, int anillo, int nat);
};

void borrar(listaAnillos& l, int anillo, int nat){
    listaAnillos::nodoAnillo* aux=l.primero;
    while(aux->valor<anillo){
        aux=aux->sig;
    }
    if(aux->valor==anillo){
        listaAnillos::nodoAnillo::nodoNat* borrar= aux->hijo;
        listaAnillos::nodoAnillo::nodoNat* padre= aux->hijo;
        while(borrar->valor<nat){
            padre=borrar;
            borrar=borrar->sig;
        }
        if(borrar->valor==nat){
            padre->sig=borrar->sig;
            delete(borrar);
            borrar=padre->sig;
        }
    }
}