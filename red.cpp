#include "red.h"
#include<iostream>


Red::Red() {}

void Red::agregarEnrutador(Enrutador enrutador){
    enrutadores.push_back(enrutador);
}

void Red::eliminarEnrutador(char nombreEnrutador){
    bool eliminado = false;
    //entramos a cada objeto y buscamos su clave, si su clave es igual a la de nombreEnrutador la eliminamos con el erase(iterador)
    for(auto i = enrutadores.begin();i!=enrutadores.end();i++){
        if(i->obtenerNombre() == nombreEnrutador){
            enrutadores.erase(i);
            bool eliminado = true;
        }
    }

    cout<<(eliminado?"Enrutador Eliminado correctamente \n" : "El enrutador no existe \n");

}

void Red::mostrarEnrutadores(){
    cout<<"Red de enrutadores : \n";
        for(auto it = enrutadores.begin();it!=enrutadores.end();it++){
        cout<<it->obtenerNombre()<<endl;
        }
    }


