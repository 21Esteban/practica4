#include "enrutador.h"
#include<iostream>

using namespace std;

Enrutador::Enrutador(char nombre) {
    this->nombre = nombre;

}


void Enrutador::agregarEnlace(char destino,int costo){
    this->tablaEnrutamiento[destino] = costo;
}

void Enrutador::eliminarEnlace(char destino){
    this->tablaEnrutamiento.erase(destino);
}


char Enrutador::obtenerNombre(){
    return this->nombre;
}

int Enrutador::obtenerCosto(char destino){
    auto costo = this->tablaEnrutamiento.find(destino);//map::find(key): Esta función busca la clave especificada en el mapa. Si encuentra la clave, devuelve un iterador que apunta al elemento correspondiente. Si no encuentra la clave, devuelve un iterador que apunta a la última posición del mapa (es decir, map.end()).
    if(costo != this->tablaEnrutamiento.end()){
        return costo->second;
    }else{
        return INT_MAX;
    }
}


void Enrutador::imprimirTablaEnrutamiento() {
    cout << "Tabla de enrutamiento del enrutador " << this->nombre << ":\n";
    for (auto iterador = this->tablaEnrutamiento.begin();iterador != this->tablaEnrutamiento.end();iterador++) {
        cout << "Destino: " << iterador->first << ", Costo: " << iterador->second << "\n";
    }
}
