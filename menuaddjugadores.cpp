#include <iostream>
using namespace std;
//indicamos la estructura a utilizar en la funcion, indicando primeramente el maximo de jugadores
const int MAX_JUGADORES = 4;

struct Jugador {
    string nombre;
    int numFallos;
};

Jugador jugadores[MAX_JUGADORES];

int agregarJugadores() {
    int n;
    //un do while, cuando se le pide al usuario el numero de jugadores, si ingresa otro numero 
    //que no este en el rango de (1-4) se repite.
    do {
        cout << "Cuantos jugadores van a jugar? (1-4): ";
        cin >> n;

        if (n < 1 || n > MAX_JUGADORES) {
            cout << "Numero de jugadores no valido. Intente nuevamente." << endl;
        }
    } while (n < 1 || n > MAX_JUGADORES);
    //un bucle for para gregar los nombres de los jugadores segun el numero introducido.
    for (int i = 0; i < n; i++) {
        cout << "Agregue el nombre del jugador " << (i + 1) << ": ";
        cin >> jugadores[i].nombre;
        jugadores[i].numFallos = 0; // Inicializamos numFallos a 0
    }

    cout << "Jugadores agregados:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Jugador " << (i + 1) << ": " << jugadores[i].nombre << endl;
    }

    return n;
}