#include <iostream>
#include "red.h"
#include "enrutador.h"
#include "menu.h"

using namespace std;

int main()
{
    Red red;

    mostrarMenu(red);

    Enrutador router1('a');
    Enrutador router2('b');

    router1.agregarEnlace('b',4);
    router1.agregarEnlace('c',2);
    router1.imprimirTablaEnrutamiento();
    router1.eliminarEnlace('b');
    router1.imprimirTablaEnrutamiento();


    red.mostrarEnrutadores();
    red.agregarEnrutador(router1);
    red.agregarEnrutador(router2);
    red.mostrarEnrutadores();


    cout << "Hello World!" << endl;
    return 0;


}
