#include <iostream>
#include<string>
#include "red.h"
#include "enrutador.h"
#include "menu.h"

using namespace std;

string filename = "C:/Users/moroc/Desktop/PracticasInfo/practica4/build/Desktop-Debug/debug/red_prueba.txt";

int main()
{
    Red red;
    red.setearEnrutadoresDesdeArchivo(filename);

    //agregar enrutadores de forma manual sin archivo txt

   /* red.agregarEnrutador('a');
    red.agregarEnrutador('b');
    red.agregarEnrutador('c');
    red.agregarEnrutador('d');*/


//nos muestras los enrutadores y sus rutas y costos
    red.mostrarEnrutadores();

//nos muestra un enrutador y su ruta y costos
    //red.obtenerEnrutador('A');
   /* red.obtenerEnrutador('a');
    red.enlazarEnrutadores('a','b',5);
    red.enlazarEnrutadores('c','b',10);
    red.enlazarEnrutadores('d','b',10);
    red.enlazarEnrutadores('d','a',10);
    red.enlazarEnrutadores('z','a',10);
    red.obtenerEnrutador('a');*/

    //cout << "Hello World!" << endl;

    //ruta mas corta

    red.rutaMasCorta('A','E');
    return 0;


}
