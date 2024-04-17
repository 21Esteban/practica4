#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include<string>
#include <map>
using namespace std;

class Enrutador{
private:
    char nombre;
    //esto es como un diccinario que va a tener la tabla de enrutamiento
    map<char,int>tablaEnrutamiento; //destino -> costo



public:
    //Constructor del objeto
    Enrutador(char nombre);

    void agregarEnlace(char destino,int costo);

    void eliminarEnlace(char destino);

    char obtenerNombre() ;

    int obtenerCosto(char destino);

    void imprimirTablaEnrutamiento();





};

#endif // ENRUTADOR_H
