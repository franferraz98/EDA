#include <iostream>

using namespace std;


struct abbDirectorios{
private:
    string nombre;
    int numHijos;
    int numFicheros;
    struct abbDirectorios * hijos[100];
    string ficheros[100];
public:
    friend void crear(abbDirectorios& a, string c);
    friend bool anyadirDirectorio(abbDirectorios& a, string nombre, string padre);
    friend bool anyadirFichero(abbDirectorios& a, string fichero, string padre);
    friend bool existe(abbDirectorios a, string buscado);
    friend bool obtenerDirectorio(abbDirectorios a, abbDirectorios& result, string nombre);
    friend bool obtenerFichero(abbDirectorios a, string& result, string nombre);
    friend void mostrarTodos(abbDirectorios a);
};

void crear(abbDirectorios& a, string c){
    a.nombre=c;
    a.numHijos=0;
    a.numFicheros=0;
}

bool anyadirDirectorio(abbDirectorios& a, string nombre, string padre){
    if(padre==a.nombre){
        abbDirectorios * nuevo= new abbDirectorios;
        crear(*nuevo,nombre);
        a.hijos[a.numHijos]=nuevo;
        a.numHijos++;
        return true;
    }else{
        bool result= false;
        int i=0;
        while(!result && i<a.numHijos){
            result= anyadirDirectorio(*a.hijos[i],nombre,padre);
            i++;
        }
        return result;
    }
}

bool anyadirFichero(abbDirectorios& a, string fichero, string padre){
    if(padre==a.nombre){
        a.ficheros[a.numFicheros]=fichero;
        a.numFicheros++;
        return true;
    }else{
        bool result= false;
        int i=0;
        while(!result && i<a.numHijos){
            result= anyadirFichero(*a.hijos[i],fichero,padre);
            i++;
        }
        return result;
    }
}

bool existe(abbDirectorios a, string buscado){
    bool result= false;
    if(buscado==a.nombre){
        return true;
    }else{
        for(int i=0; i<a.numFicheros; i++){
            if(buscado==a.ficheros[i]){
                result= true;
            }
        }
        if(!result){
            int i=0;
            while(!result && i<a.numHijos){
                result= existe(*a.hijos[i],buscado);
                i++;
            }
        }
        return result;
    }
}

bool obtenerDirectorio(abbDirectorios a, abbDirectorios& result, string nombre){
    bool encontrado= false;
    if(nombre==a.nombre){
        result=a;
        encontrado= true;
    }else{
        int i=0;
        while(i<a.numHijos && !encontrado){
            encontrado= obtenerDirectorio(*a.hijos[i],result,nombre);
            i++;
        }
    }

    return encontrado;
}

bool obtenerFichero(abbDirectorios a, string& result, string nombre){
    bool encontrado= false;
    int i=0;
    while(i<a.numFicheros && !encontrado){
        if(a.ficheros[i]==nombre){
            result=a.ficheros[i];
            encontrado=true;
        }
        i++;
    }
    i=0;
    while(i<a.numHijos && !encontrado){
        encontrado= obtenerFichero(*a.hijos[i],result,nombre);
        i++;
    }

    return encontrado;
}

void mostrarTodos(abbDirectorios a){
    cout << a.nombre << endl;
    for(int i=0; i<a.numFicheros; i++){
        cout << a.ficheros[i] << " ";
    }
    cout << endl;
    for(int j=0;j<a.numHijos; j++){
        mostrarTodos(*a.hijos[j]);
        cout << endl;
    }
}