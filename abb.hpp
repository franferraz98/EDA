#include <iostream>

using namespace std;

template <typename T> struct abb;
template <typename T> void inicializar(abb<T>& a);
template <typename T> void anyadir(abb<T>& a, T elem);
template <typename T> bool esVacio(const abb<T> a);
template <typename T> void preorden(const abb<T> a);
template <typename T> void siguiente(struct abb<T>::Nodo*& i, const abb<T> a);
template <typename T> struct abb<T>::Nodo* minimo(const abb<T> a);
template <typename T> struct abb<T>::Nodo* maximo(const abb<T> a);
template <typename T> void borrar(abb<T>& a, T elem);
template <typename T> void borrarAux(struct abb<T>::Nodo*& n, T elem);

template <typename T>
struct abb{
private:
    struct Nodo{
        T dato;
        Nodo* izq;
        Nodo* dch;
    };
    Nodo* raiz;
public:
    friend void inicializar<T>(abb<T>& a);
    friend void anyadir<T>(abb<T>& a, T elem);
    friend bool esVacio<T>(const abb<T> a);
    friend void preorden<T>(const abb<T> a);
    friend void siguiente<T>(struct abb<T>::Nodo*& i, const abb<T> a);
    friend struct abb<T>::Nodo* minimo<T>(const abb<T> a);
    friend struct abb<T>::Nodo* maximo<T>(const abb<T> a);
    friend void borrar<T>(abb<T>& a, T elem);
    friend void borrarAux<T>(struct abb<T>::Nodo*& n, T elem);
};

template <typename T>
void inicializar(abb<T>& a){
    a.raiz=nullptr;
}

template <typename T>
void anyadir(abb<T>& a, T elem){
    typename abb<T>::Nodo* nuevo= new typename abb<T>::Nodo;
    typename abb<T>::Nodo* padre;
    nuevo->dato=elem;
    nuevo->izq=nullptr;
    nuevo->dch=nullptr;
    if(esVacio(a)){
        a.raiz=nuevo;
    }
    else{
        typename abb<T>::Nodo* actual= new typename abb<T>::Nodo;
        actual=a.raiz;
        while(actual!=nullptr){
            padre=actual;
            if(nuevo->dato > actual->dato){
                actual= actual->dch;
            }
            else{
                actual=actual->izq;
            }
        }
        if(nuevo->dato < padre->dato){
            padre->izq= nuevo;
        }
        else{
            padre->dch= nuevo;
        }
    }
}

template <typename T>
bool esVacio(const abb<T> a){
    return a.raiz==nullptr;
}

template <typename T>
struct abb<T>::Nodo* minimo(const abb<T> a){
    typename abb<T>::Nodo* n;
    n=a.raiz;
    while(n->izq!=nullptr){
        n=n->izq;
    }
    return n;
}

template <typename T>
struct abb<T>::Nodo* maximo(const abb<T> a){
    typename abb<T>::Nodo* n;
    n=a.raiz;
    while(n->dch!=nullptr){
        n=n->dch;
    }
    return n;
}

template <typename T>
void siguiente(struct abb<T>::Nodo*& i, const abb<T> a){
    if(i->dch!=nullptr){
        i=i->dch;
        while(i->izq!=nullptr){
            i=i->izq;
        }
    }
    else{
        typename abb<T>::Nodo* n;
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

template <typename T>
void preorden(const abb<T> a){
    typename abb<T>::Nodo* i;
    i= minimo(a);
    while(i!= maximo(a)){
        cout << i->dato << endl;
        siguiente(i,a);
    }
    cout << i->dato << endl;
}

template <typename T>
void borrar(abb<T>& a, T elem){
    borrarAux(a.raiz,elem);
    
}

template <typename T>
void borrarAux(struct abb<T>::Nodo*& n, T elem){
    typename abb<T>::Nodo* aux;
    if(elem<n->dato){
        borrarAux(n->izq,elem);
    }else if(elem>n->dato){
        borrarAux(n->dch,elem);
    }else if(elem==n->dato){
        if(n->izq==nullptr){
            aux=n;
            n=n->dch;
            delete(aux);
        }else{
            typename abb<T>::Nodo* mx;
            abb<T> a;
            a.raiz=n;
            mx= maximo(a);
            n->dato=mx->dato;
            borrarAux(n->izq,n->dato);
        }
    }
}

