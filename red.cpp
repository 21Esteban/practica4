#include "red.h"
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <random>
#include <unordered_set>

Red::Red() {}

void Red::agregarEnrutador(char nombre){
    enrutadores.insert({nombre, Enrutador(nombre)});

}

void Red::eliminarEnrutador(char nombreEnrutador){
    auto it = enrutadores.find(nombreEnrutador);//map::find(key): Esta función busca la clave especificada en el mapa. Si encuentra la clave, devuelve un iterador que apunta al elemento correspondiente. Si no encuentra la clave, devuelve un iterador que apunta a la última posición del mapa (es decir, map.end()).
    if(it != enrutadores.end()){
        enrutadores.erase(nombreEnrutador);
        cout<<"Enrutador Eliminado correctamente \n";
    }else{
        cout<< "El enrutador no existe \n";
    }

}


void Red::actualizarTablaEnrutamiento(char nombreEnrutador, map<char, int> tablaEnrutamiento) {
    auto it = enrutadores.find(nombreEnrutador);
    if(it != enrutadores.end()){
        it->second.actualizarTablaEnrutamiento(tablaEnrutamiento);
    }else{
        cout<<"La tabla de enrutamiento para el enrutador " << nombreEnrutador <<" no existe";

    }

}


void Red::obtenerEnrutador(char nombreEnrutador){
    auto it = enrutadores.find(nombreEnrutador);

    if(it!=enrutadores.end()){
        it->second.imprimirTablaEnrutamiento();
    }else{
        cout<<"EL enrutador no existe \n";
    }
}

void Red::mostrarEnrutadores(){
    cout<<"Red de enrutadores : \n";
        for(auto it = enrutadores.begin();it!=enrutadores.end();it++){
        it->second.imprimirTablaEnrutamiento();
        }
    }

void Red::enlazarEnrutadores(char Enrutador1, char Enrutador2, int costo) {
    auto it1 = enrutadores.find(Enrutador1);
    auto it2 = enrutadores.find(Enrutador2);
    if (it1 != enrutadores.end() && it2 != enrutadores.end()) {
        it1->second.agregarEnlace(Enrutador2, costo);
        it2->second.agregarEnlace(Enrutador1, costo);
    } else {
        cout << "Algunos de los enrutadores no existe \n";
    }
}

void Red::setearEnrutadoresDesdeArchivo(string filename){

    ifstream archivo(filename);

    if (!archivo.is_open()) {
        cout<< "Error al abrir el archivo." << endl;
        return;
    }

    string linea;

    while(getline(archivo,linea)){
        /*La clase istringstream permite tratar una cadena de caracteres como si fuera un flujo de entrada, lo que facilita la lectura de datos                 de la cadena utilizando los mismos operadores de extracción (>>) que se utilizan para leer desde otros flujos de entrada.*/
        char enrutador1,enrutador2;
        int costo;
        //creamos la instancia de la clase istringstream que nos va a permitir leer una cadena ;
        istringstream iss(linea);

        if (!(iss >> enrutador1 >> enrutador2 >> costo)) {
            cout << "Error al leer la línea: " << linea << "\n";
            continue;
        }

        if (enrutadores.find(enrutador1) == enrutadores.end()) {
            enrutadores.insert({enrutador1, Enrutador(enrutador1)});
        }
        if (enrutadores.find(enrutador2) == enrutadores.end()) {
            enrutadores.insert({enrutador2,Enrutador(enrutador2)});
        }

        enlazarEnrutadores(enrutador1, enrutador2, costo);
    }


     archivo.close();
    cout<<"Archivo cerrado correctamente";

}

pair<int, vector<char>> Red::rutaMasCorta(char enrutadorInicio, char enrutadorFinal) {
    priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>, greater<>> cola;
    cola.push({0, {enrutadorInicio}});
    /*unordered_set garantiza que cada elemento en el conjunto aparezca solo una vez. Si intentas insertar un elemento que ya está presente en el        conjunto, la inserción no tiene efecto.*/
    unordered_set<char> visitados;
    while (!cola.empty()) {
        auto [costo, camino] = cola.top();
        cola.pop();
        char id = camino.back();
        if (visitados.find(id) == visitados.end()) {
            visitados.insert(id);
            if (id == enrutadorFinal) {
                cout<<"La ruta mas corta es : ";
                    for(char nodo : camino){
                    cout<<nodo<<' ';
                }
                    cout << "\nCosto total: " << costo <<endl;
                return {costo, camino};
            }
            for (auto [destino, costo_enlace] : enrutadores[id].obtenerTablaEnrutamiento()) {
                if (visitados.find(destino) == visitados.end()) {
                    auto copia_camino = camino;
                    copia_camino.push_back(destino);
                    cola.push({costo + costo_enlace, copia_camino});
                }
            }
        }
    }
    cout << "No hay ruta disponible." <<endl;
    return {-1, {}};
}



