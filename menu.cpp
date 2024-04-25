// Función para mostrar el menú y manejar la interacción con el usuario
#include<iostream>
#include"menu.h"
#include"enrutador.h"
#include<string>
#include"red.h"

using namespace std;

void mostrarMenu(Red &red) {
    int opcion;
    char caracter;
    char caracter1, caracter2;
    int costoEnvio;
    int numeroDeRouters;
    while (true) {
        cout << "Menu: \n"<< endl;
        cout << "1. Agregar enrutador \n" << endl;
        cout << "2. Eliminar enrutador \n" << endl;
        cout << "3. mostrar tabla de enrutamiento \n" << endl;
        cout << "4. Obtener costo de enviar un paquete \n" << endl;
        cout << "5. Mostrar camino eficiente para enviar un paquete \n" << endl;
        cout << "6. Generar red aleatoria \n" << endl;
        cout << "7. Enlazar enrutadores \n" << endl;


        cout << "8. Salir \n" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout<<"Ingrese un nombre para el enrutador : \n";
            caracter = recibirCaracter();
            red.agregarEnrutador(caracter);
            break;
        case 2:
            cout<<"Ingrese el enrutador para eliminar enrutador : \n";
            caracter = recibirCaracter();
            red.eliminarEnrutador(caracter);
            break;
        case 3:
           // cout<<"Ingrese el enrutador para mostrar su tabla de enrutamiento : \n";
            red.mostrarEnrutadores();
            //Aqui debe de ir una funcion que nos permita crear una tabla de enrutamiento para actualizar en el enrutador

            break;
        case 4:
            // Lógica para obtener costo de enviar un paquete
            cout<<"El costo de enviar un paquete \n";
            recibirCaracteres(caracter1,caracter2);
            costoEnvio = red.costoDePaquete(caracter1,caracter2);
            cout<<costoEnvio;
            break;
        case 5:
            // Lógica para mostrar camino eficiente para enviar un paquete
            cout<<"Rutas mas corta o de menos costo de un enrutador a otro : \n";
            recibirCaracteres(caracter1,caracter2);
            red.rutaMasCorta(caracter1,caracter2);
            break;
        case 6:
            // Lógica para generar red aleatoria
            cout<<"Ingrese el numero de enrutadores para generar la red aleatoria : ";
            cin>>numeroDeRouters;
            cout<<"Generando red Aleatoria ... \n";
            red.generarRedAleatoria(numeroDeRouters);
            break;
        case 7:
            //logica para añadir enlaces
            int costo;
            recibirCaracteres(caracter1,caracter2);
            cout<<"Ingrese el costo entre esos enrutadores : ";
            cin>>costo;
            red.enlazarEnrutadores(caracter1,caracter2,costo);
            break;
        case 8:
            cout << "Saliendo del programa..." << endl;
            return;
        default:
            cout << "Opción inválida. Por favor ingrese un número entre 1 y 10." << endl;
        }
    }
}

char recibirCaracter(){
    char nombre;
    bool flag = true;
    while(flag){
        cout<<"Ingrese el nombre del enrutador ";
        cin>>nombre;
        if(nombre>64 && nombre<122){
            flag = false;
        }
    }

    return nombre;
}


void recibirCaracteres(char &caracter1 , char &caracter2){
    bool flag = true;
    while(flag){

        cout<<"Ingrese el nombre del enrutador de inicio : \n";
        cin>>caracter1;
        cout<<"Ingrese el nombre del enrutador final : \n";
        cin>>caracter2;

        if(((caracter1>=65 && caracter1<=90) || (caracter1>=97 && caracter1<=122)) &&
            ((caracter2>=65 && caracter2<=90) || (caracter2>=97 && caracter2<=122))){
            flag = false;
        }
    }

}
