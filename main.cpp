#include "abbDirectorios.hpp"

using namespace std;

int main(){
    abbDirectorios a;
    crear(a,"root");
    bool aux;
    aux= anyadirDirectorio(a,"cosa","root");
    aux= anyadirFichero(a,"f1","cosa");
    aux= anyadirFichero(a,"f2","cosa");
    aux= anyadirFichero(a,"f3","cosa");

    aux= anyadirDirectorio(a,"coso","root");
    aux= anyadirFichero(a,"f1","coso");
    aux= anyadirFichero(a,"f2","coso");
    aux= anyadirFichero(a,"f3","coso");

    aux= anyadirDirectorio(a,"cosi","cosa");
    aux= anyadirFichero(a,"f1","cosi");
    aux= anyadirFichero(a,"f2","cosi");
    aux= anyadirFichero(a,"f3","cosi");

    aux= anyadirFichero(a,"f1","cosu");
    cout << aux << endl;

}