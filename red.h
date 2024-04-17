#ifndef RED_H
#define RED_H
#include<string>
#include<vector>

#include "enrutador.h"

class Red{
    string nombre;
    vector<Enrutador> enrutadores;

public:
    Red();
    void agregarEnrutador(Enrutador enrutador);
    void eliminarEnrutador(char nombreEnrutador);
    Enrutador* obtenerEnrutador(char nombreEnrutador);
    void imprimirTablaEnrutamientoRed() const;
    void mostrarEnrutadores();
};

#endif // RED_H
