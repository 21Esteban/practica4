// Función para mostrar el menú y manejar la interacción con el usuario
#include<iostream>
#include"menu.h"
#include"enrutador.h"
#include<string>
#include"red.h"

using namespace std;

void mostrarMenu(Red &red) {
    int opcion;
    while (true) {
        cout << "Menu: \n"<< endl;
        cout << "1. Agregar enrutador \n" << endl;
        cout << "2. Eliminar enrutador \n" << endl;
        cout << "3. Actualizar tabla de enrutamiento \n" << endl;
        cout << "4. Obtener costo de enviar un paquete \n" << endl;
        cout << "5. Mostrar camino eficiente para enviar un paquete \n" << endl;
        cout << "6. Generar red aleatoria \n" << endl;
        cout << "7. Salir \n" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            crearEnrutador(red);
            break;
        case 2:
            // Lógica para eliminar enrutador
            break;
        case 3:
            // Lógica para actualizar tabla de enrutamiento
            break;
        case 4:
            // Lógica para obtener costo de enviar un paquete
            break;
        case 5:
            // Lógica para mostrar camino eficiente para enviar un paquete
            break;
        case 6:
            // Lógica para generar red aleatoria
            break;
        case 7:
            cout << "Saliendo del programa..." << endl;
            return;
        default:
            cout << "Opción inválida. Por favor ingrese un número entre 1 y 7." << endl;
        }
    }
}

void crearEnrutador(Red &red){
    char nombreEnrutador;
    int numeroDeEnrutadores;
    cout<<"Cuantos enrutadores va a agregar : \n";
    cin>>numeroDeEnrutadores;
    for(int i = 0 ; i < numeroDeEnrutadores; i++){
        cout<<"Ingrese el nombre del enrutador"<<i+1<<" :" ;
        cin>>nombreEnrutador;
        Enrutador nuevoEnrutador(nombreEnrutador);
        red.agregarEnrutador(nuevoEnrutador);

    }

    red.mostrarEnrutadores();

}
