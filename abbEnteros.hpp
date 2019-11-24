#include <iostream>

using namespace std;

struct abbEnteros{
private:
    struct Nodo{
        int dato;
        Nodo* izq;
        Nodo* dch;
    };
    Nodo* raiz;
    int numElem;
public:
    friend void inicializar(abbEnteros& a);
    friend void anyadir(abbEnteros&a, int e);
    friend void minimo(abbEnteros a, struct abbEnteros::Nodo*& b);
    friend void maximo(abbEnteros a, struct abbEnteros::Nodo*& b);
    friend void siguiente(abbEnteros a, struct abbEnteros::Nodo*& i);
    friend void preorden(abbEnteros a);
    friend void borrar(abbEnteros& a, int e);
    friend void borrarAux(struct abbEnteros::Nodo*& n, int e);

};

void inicializar(abbEnteros& a){
    a.raiz=nullptr;
    a.numElem=0;
}

void anyadir(abbEnteros& a, int e){
    abbEnteros::Nodo* n= new abbEnteros::Nodo;
    n->dato= e;
    n->izq= nullptr;
    n->dch= nullptr;
    abbEnteros::Nodo* p;
    p= a.raiz;
    if(p==nullptr){
        a.raiz= n;
    }
    else{
        abbEnteros::Nodo* actual= new abbEnteros::Nodo;
        actual=a.raiz;
        while(actual!=nullptr){
            p=actual;
            if(n->dato > actual->dato){
                actual= actual->dch;
            }
            else{
                actual=actual->izq;
            }
        }
        if(n->dato < p->dato){
            p->izq= n;
        }
        else{
            p->dch= n;
        }
    }
}

void minimo(abbEnteros a, struct abbEnteros::Nodo*& b){
    abbEnteros::Nodo* n;
    n=a.raiz;
    while(n->izq!=nullptr){
        n=n->izq;
    }
    b=n;
}

void maximo(abbEnteros a, struct abbEnteros::Nodo*& b){
    abbEnteros::Nodo* n;
    n=a.raiz;
    while(n->dch!=nullptr){
        n=n->dch;
    }
    b=n;
}

void siguiente(abbEnteros a, struct abbEnteros::Nodo*& i){
    if(i->dch!=nullptr){
        i=i->dch;
        while(i->izq!=nullptr){
            i=i->izq;
        }
    }
    else{
        abbEnteros::Nodo* n;
        n=a.raiz;
        while(n->izq!=i){
            if(i->dato <= n->dato){
                n=n->izq;
            }
            else{
                n=n->dch;
            }
        }
        i=n;
    }
}

void preorden(abbEnteros a){
    abbEnteros::Nodo* i;
    abbEnteros::Nodo* m;
    minimo(a,i);
    maximo(a,m);
    while(i->dato < m->dato){
        cout << i->dato << endl;
        siguiente(a,i);
    }
    cout << i->dato << endl;
}

void borrar(abbEnteros& a, int e){
    borrarAux(a.raiz,e);
}


void borrarAux(struct abbEnteros::Nodo*& n,int e){
    struct abbEnteros::Nodo* aux;
    if(n->dato < e){
        borrarAux(n->dch,e);
    }else if(n->dato >e){
        borrarAux(n->izq,e);
    }else if(n->dato==e){
        if(n->izq==nullptr){
            aux=n;
            n=n->dch;
            delete(aux);
        }else{
            if(n->izq==nullptr){
                aux=n;
                n=n->dch;
                delete(aux);
            }else{
                typename abbEnteros::Nodo* mx;
                abbEnteros a;
                a.raiz=n;
                maximo(a,mx);
                n->dato=mx->dato;
                borrarAux(n->izq,n->dato);
            }
        }
    }
}