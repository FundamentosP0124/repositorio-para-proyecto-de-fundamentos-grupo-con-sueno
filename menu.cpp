#include <iostream>
using namespace std; 

int menuPrincipal(); 
int comenzarJuego(); 
int menuAyuda(); 
int mostrarIntegrantes(); 
int salir(); 
 

int main(){
    int opcion; 

    while(opcion != 4){
        menuPrincipal(); 
        cin >> opcion; 

        switch(opcion){
        case 1: 
           comenzarJuego(); 
           break; 
        case 2: 
           menuAyuda(); 
           break; 
        case 3: 
            mostrarIntegrantes();
            break; 
        case 4: 
            salir(); 
            break; 
        default: 
            cout << "Opcion no valida. Seleccione una opcion entre 1 y 4" << endl; 
            break; 
        }
    }
    
    return 0; 
}

int menuPrincipal(){ 
cout << "*******************" << endl;
cout << "JUEGO DE AHORCADO" << endl << endl; 
cout << "******************" << endl; 
cout << "1. Comenzar a jugar" << endl; 
cout << "2. Mostrar menu de ayuda" << endl; 
cout << "3. Mostrar integrantes del proyecto" << endl; 
cout << "4. Salir" << endl;
cout << "Seleccione una opcion: "; 
}

int comenzarJuego(){

}

int menuAyuda(){
    cout << endl << endl; 
    cout << "COMO JUGAR AHORCADO: " << endl << endl; 
    cout << " (1) El juego elige una palabra al azar dependiendo del nivel de dificultad seleccionado" << endl; 
    cout << " (2) El jugador va llenando los espacios con cada letra de la palabra" << endl; 
    cout << " (3) Si la letra introducida se encuentra en la palabra, se llenara el espacio y se mostrara en la posicion correcta" << endl; 
    cout << " (4) Si la letra introducida no se encuentra en la palabra, se dibujara una parte del ahorcado" << endl; 
    cout << " (5) Se permite introducir solo seis letras incorrectas, despues de esto el dibujo del ahorcado se completa" << endl; 
    cout << " (6) El juego finaliza cuando se llena la palabra o se completa el dibujo del ahorcado" << endl << endl; 
}

int mostrarIntegrantes(){
    cout << "INTEGRANTES DEL PROYECTO: " << endl << endl; 
    cout << "Sebastian Leonardo Molina Santos 00161024" << endl; 
    cout << "Fernando Josue Escamilla Rivera 00053324" << endl; 
    cout << "Kristen Nicole Cruz Rodriguez 00051524" << endl; 
}

int salir(){
    cout << "Gracias por jugar ahorcado" << endl; 
}
