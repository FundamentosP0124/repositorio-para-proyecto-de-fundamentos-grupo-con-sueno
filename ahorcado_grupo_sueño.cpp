#include<iostream>
#include<time.h>
#include<random>
#include<conio.h>
#include<string.h>

using namespace std;

const int MAX_JUGADORES = 4;

struct jugador
{
   string nombre;
   int numFallos;
};
jugador jugadores[MAX_JUGADORES];

//Funcion para mostrar el menu principal
int menuPrincipal(); 

//Funcion que muestra el menu comenzar juego
int menuJuego(); 

//funcion para agregar jugadores
int agregarJugadores();

//Funcion para mostrar el menu de ayuda
int menuAyuda(); 

//Funcion para mostrar los integrantes del proyecto
int mostrarIntegrantes(); 

//Funcion para salir del juego
int salir();

void menu_dificultad();

//Funcion para seleccionar un numero aleatorio entre 0 y 9
int numero_aleatorio();

//Funcion para seleccionar una palabra aleatoria dependiendo de la dificultad
string seleccion_palabra(int diff);

//Funcion del juego del ahorcado
void Juego_Principal();

//Funcion para dibujar al muñeco del ahorcado
int dibujo_ahorcado(int x);

int main(){
    int opcion;

    //Se repite mientras la opcion no sea igual a 4 (salir)
    while(opcion != 4){
        menuPrincipal(); 
        cin >> opcion; 

        switch(opcion){
        case 1: 
           menuJuego(); 
           break; 
        case 2: 
           menuAyuda(); //Se muestra el menu de ayuda 
           break; 
        case 3: 
            mostrarIntegrantes(); //Se muestra el menu de integrantes
            break; 
        case 4: 
            salir(); //Se sale del juego y se cierra el menu
            break; 
        default: 
            cout << "Opcion no valida. Seleccione una opcion entre 1 y 4" << endl; 
            break; 
        }
    }

    return 0;
}

//Opciones del menu principal del juego
int menuPrincipal(){ 
cout << endl; 
cout << "====================================\n";
cout << "             AHORCADO    \n";
cout << "====================================\n";
cout << "[1] Comenzar a jugar\n"; 
cout << "[2] Mostrar menu de ayuda\n"; 
cout << "[3] Mostrar integrantes del proyecto\n"; 
cout << "[4] Salir\n\n";
cout << "Seleccione una opcion: "; 
}

int menuJuego(){
    int accion; 

    cout << endl; 
    cout << "MENU DE COMENZAR JUEGO\n"; 
    cout << "[1] Menu de jugadores\n"; 
    cout << "[2] Iniciar juego\n"; 
    cout << "Ingrese su opcion: "; 
    cin >> accion; 

    switch(accion){
        case 1: 
        agregarJugadores(); 
        break; 
        case 2: 
        Juego_Principal(); 
        break; 
        default: 
        cout << "Valor ingresado no valido. Intente de nuevo" << endl; 
        break; 
    }
}

int agregarJugadores() {
    int numero; 
    
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


int menuAyuda(){
    int num; 
    bool volverMenu = false; 
    
    //Permite volver al menu principal al mostrar las instrucciones  
    while(!volverMenu){
    cout << endl << endl; 
    cout << "COMO JUGAR AHORCADO: " << endl << endl; 
    cout << " (1) El juego elige una palabra al azar dependiendo del nivel de dificultad seleccionado" << endl; 
    cout << " (2) El jugador va llenando los espacios con cada letra de la palabra" << endl; 
    cout << " (3) Si la letra introducida se encuentra en la palabra, se llenara el espacio y se mostrara en la posicion correcta" << endl; 
    cout << " (4) Si la letra introducida no se encuentra en la palabra, se dibujara una parte del ahorcado" << endl; 
    cout << " (5) Se permite introducir solo seis letras incorrectas, despues de esto el dibujo del ahorcado se completa" << endl; 
    cout << " (6) El juego finaliza cuando se llena la palabra o se completa el dibujo del ahorcado" << endl << endl;

    cout << "Ingresar 1 para volver al menu principal: "; 
    cin >> num; 
    
    //Si el numero ingresado es 1, se regresa al menu principal
    if(num == 1){
        volverMenu = true; 
    } //Si el numero ingresado no es 1, se vuelve a presentar la opcion de volver al menu 
    else{
        cout << "Numero ingresado no valido. Intente de nuevo" << endl; 
    }
    }
}

int mostrarIntegrantes(){
    int num; 
    bool volverMenu = false; 

    while(!volverMenu){
    cout << endl; 
    cout << "INTEGRANTES DEL PROYECTO: " << endl << endl; 
    cout << "Leonardo Sebastian Molina Santos 00161024" << endl; 
    cout << "Fernando Josue Escamilla Rivera 00053324" << endl; 
    cout << "Kristen Nicole Cruz Rodriguez 00051524" << endl << endl;

    cout << "Ingresar 1 para volver al menu principal: "; 
    cin >> num; 
    
    //Si el numero ingresado es 1, se regresa al menu principal
    if(num == 1){
        volverMenu = true; 
    } //Si el numero ingresado no es 1, se vuelve a presentar la opcion de volver al menu
    else{
        cout << "Numero ingresado no valido. Intente de nuevo" << endl; 
    }
}
}


int salir(){
    cout << "Gracias por jugar ahorcado!" << endl; 
}

void menu_dificultad(){
    int dificultad; 
    cout<<"===================\n";
    cout<<"Elija la dificultad\n";
    cout<<"===================\n\n";

    cout<<"\t[1] Facil\n";
    cout<<"\t[2] Normal\n";
    cout<<"\t[3] Dificil\n";
    cin >> dificultad; 
}

void Juego_Principal() {
    //Variables de la palabra a adivinar
    string palabra = seleccion_palabra(2); // selecciona la palabra
    int num_characteres_palabra = palabra.size();
    int numjugadores = agregarJugadores(); // agrega jugadores y obtiene su número
    //Rondas del juego
    int rondas = 0;

     //La palabra/guiones que se mostraran en pantalla
    string mostrar(num_characteres_palabra, '_');
    //Letra que introducira el jugador
    char letra; 
    int fallos = 0; // número de fallos en el juego
    //Variables para confirmar si la palabra esta completamente adivinada y si la letra insertada es correcta
    bool palabra_completa = false; 
    bool letra_correcta = false;
    int num;
    bool volverMenu = false;

    while (!volverMenu) {
        while (fallos < 6 && !palabra_completa) { // Mientras los fallos sean menores a 6 y la palabra no esté completa
            cout << "========AHORCADO========\n";
            cout << "      Ronda " << rondas << endl;

            for (int i = 0; i < numjugadores; i++) { // Itera a través de los jugadores
                cout << "    Turno de: " << jugadores[i].nombre << endl;
                dibujo_ahorcado(fallos);
                cout << endl;

                letra_correcta = false; // reinicia letra_correcta para la nueva letra

        
                for (int j = 0; j < num_characteres_palabra; j++) {
                    cout << mostrar[j] << " ";
                }
                cout << endl;
                cout << "Ingrese la letra: ";
                cin >> letra;

                for (int j = 0; j < num_characteres_palabra; j++) {
                    if (letra == palabra[j]) {
                        mostrar[j] = letra; // reemplaza el guion con la letra
                        letra_correcta = true; // indica que la letra es correcta
                    }
                }

                if (!letra_correcta) { // si la letra no está en la palabra
                    fallos++;
                    jugadores[i].numFallos++; // aumenta el número de fallos del jugador
                }

                int espacios_vacios = 0; // verifica si quedan guiones en la palabra

                // cuenta los guiones restantes en la palabra mostrada
                for (int j = 0; j < num_characteres_palabra; j++) {
                    if (mostrar[j] == '_') {
                        espacios_vacios++;
                    }
                }

                if (espacios_vacios == 0) { // si no hay espacios vacios
                    palabra_completa = true; // la palabra está completa
                }

                if (fallos >= 6 || palabra_completa) { // si el juego terminó
                    break; // salir del ciclo de turnos
                }
            }
            rondas++;
        }
        //==================Pantalla que se mostrara dependiendo si se encontro o no la palabra==================

        // muestra la palabra correcta al final del juego
        cout << "La palabra correcta era: " << palabra << endl;
        
        cout << "Ingresar 1 para volver al menu principal: ";
        cin >> num;

        // si el número ingresado es 1, se regresa al menú principal
        if (num == 1) {
            volverMenu = true;
        } else {
            cout << "Numero ingresado no valido. Intente de nuevo" << endl;
        }
    }
}
int numero_aleatorio(){
    //Usando la hora del computador del usuario se saca el numero aleatorio
    int valor = time(0);
    srand(valor);
    //Ese numero se divide entre 5 (los arreglos comienzan desde 0) porque son 5 palabras por dificultad
    int asignar_palabra = rand() % 10;

    return asignar_palabra;
}

string seleccion_palabra(int diff){
    //Variables de las palabras del juego y su dificultad
    string palabra_facil[10]={"juego","taxi","comida","redes","caida","banana","arbol","tambor","soda","cubeta"};
    string palabra_normal[10]={"desinfectante","recolectar","mosquitos","escalofrios","chocolate","congelador","destruccion","monarquia","electrico","circulacion"};
    string palabra_dificil[10]={"electrocardiograma","transustanciacion","ovoviviparo","desacostumbradamente","lactovegetarianismo","programacion","refraccion","electroencefalografista","caleidoscopio","desencadenante"};

    string palabra;
    //La funcion retorna la palabra dependiendo de la dificultad
    switch (diff){
    case 1:
        palabra = palabra_facil[numero_aleatorio()];//Se elige una palabra facil
        break;

    case 2:
        palabra = palabra_normal[numero_aleatorio()];//Se elige una palabra normal
        break;

    case 3:
        palabra = palabra_dificil[numero_aleatorio()];//Se elige una palabra dificil
        break;
    
    default:
        palabra = "Opcion incorrecta intente de nuevo";//Se repite el menu porque no insertaron un menu entre 1 y 3
        break;
    }

    return palabra;
}

int dibujo_ahorcado(int x){
    switch (x){
    case 0:
        cout<<"\t +---+ \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t======";
        break;

    case 1:
        cout<<"\t +---+ \n";
        cout<<"\t |   | \n";
        cout<<"\t O   | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t======";
        break;

    case 2:
        cout<<"\t +---+ \n";
        cout<<"\t |   | \n";
        cout<<"\t O   | \n";
        cout<<"\t |   | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t======";
        break;

    case 3:
        cout<<"\t +---+ \n";
        cout<<"\t |   | \n";
        cout<<"\t O   | \n";
        cout<<"\t/|   | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t======";
        break;

    case 4:
        cout<<"\t +---+ \n";
        cout<<"\t |   | \n";
        cout<<"\t O   | \n";
        cout<<"\t/|\\  | \n";
        cout<<"\t     | \n";
        cout<<"\t     | \n";
        cout<<"\t======";
        break;

    case 5:
        cout<<"\t +---+ \n";
        cout<<"\t |   | \n";
        cout<<"\t O   | \n";
        cout<<"\t/|\\  | \n";
        cout<<"\t  \\  | \n";
        cout<<"\t     | \n";
        cout<<"\t======";
        break;

        case 6:
        cout<<"\t +---+ \n";
        cout<<"\t |   | \n";
        cout<<"\t O   | \n";
        cout<<"\t/|\\  | \n";
        cout<<"\t/ \\  | \n";
        cout<<"\t     | \n";
        cout<<"\t======";
        break;

    default:
        break;
    }

}