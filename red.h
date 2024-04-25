#ifndef RED_H
#define RED_H
#include<string>
#include <unordered_map>
#include <map>
#include<vector>

#include "enrutador.h"

class Red{
    string nombre;
    unordered_map<char,Enrutador> enrutadores;

public:
    Red();
    void agregarEnrutador(char nombre);
    void eliminarEnrutador(char nombreEnrutador);
    void obtenerEnrutador(char nombreEnrutador);
    void actualizarTablaEnrutamiento(char nombreEnrutador, map<char, int> tablaEnrutamiento);
    void imprimirTablaEnrutamientoRed() ;
    void mostrarEnrutadores();
    void enlazarEnrutadores(char Enrutador1, char Enrutador2, int costo) ;
    void setearEnrutadoresDesdeArchivo(string filename);
    pair<int, vector<char>>rutaMasCorta(char enrutadorInicio, char enrutadorFinal);
    int costoDePaquete(char enrutadorInicio, char enrutadorFinal);
    void generarRedAleatoria(int numeroDeRouters);
};

#endif // RED_H
