#include<iostream>
#include<time.h>
#include<random>
#include<conio.h>
#include<string.h>
#include<fstream>

using namespace std;

const int MAX_JUGADORES = 4;

int rondas = 0; //Variable para el numero de rondas del juego

char regresar; //Variable para salir de sub menus

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
int numjugadores=0; //indica el numero de jugadores

//Funcion para ver jugadores
void ver_jugadores();

//Funcion para mostrar el menu de ayuda
int menuAyuda(); 

//Funcion para mostrar los integrantes del proyecto
int mostrarIntegrantes(); 

//Funcion para salir del juego
int salir();

int menu_dificultad();

//Funcion para seleccionar un numero aleatorio entre 0 y 9
int numero_aleatorio();

//Funcion para seleccionar una palabra aleatoria dependiendo de la dificultad
string seleccion_palabra(int diff);

//Funcion del juego del ahorcado
void Juego_Principal();

//Funcion para dibujar al muñeco del ahorcado
int dibujo_ahorcado(int x);

//funcion menu elegir rondas
void menu_rondas();

void pantallafinal();


int main(){
    int opcion;

    //Se repite mientras la opcion no sea igual a 4 (salir)
    while(opcion != 4){
        menuPrincipal(); 
        cin >> opcion; 
        system("cls");

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
    cout << "[1] Agregar jugadores\n";
    cout << "[2] Ver jugadores\n";  
    cout << "[3] Iniciar juego\n"; 
    cout << "[4] regresar al menu principal\n"; 
    cout << "Ingrese su opcion: "; 
    cin >> accion; 
    system("cls");

    switch(accion){
    case 1: 
        agregarJugadores(); 
        return menuJuego();
        break;

    case 2:

        if(numjugadores>0){
        ver_jugadores(); 
        } else {
            cout<<"porfavor agregue jugadores primero";
            return menuJuego();
        }
        
        break;

    case 3:
    
        if(numjugadores>0){
            Juego_Principal(); 
        } else {
            cout<<"porfavor agregue jugadores primero";
            return menuJuego();
        }
        
        break;

    case 4:
        break;

    default: 
        cout << "Valor ingresado no valido. Intente de nuevo" << endl; 
        break; 
    }
}

void pantallafinal(){
    {
    // Ordenar los jugadores por número de fallos de menor a mayor
    for (int i = 0; i < numjugadores - 1; i++) {
        for (int j = 0; j < numjugadores - i - 1; j++) {
            if (jugadores[j].numFallos > jugadores[j + 1].numFallos) {
                jugador temp = jugadores[j];
                jugadores[j] = jugadores[j + 1];
                jugadores[j + 1] = temp;
            }
        }
    }

    // Mostrar los resultados
    cout << "======= RESULTADOS FINALES =======\n";
    for (int i = 0; i < numjugadores; i++) {
        cout << i + 1 << ". " << jugadores[i].nombre << " - Fallos: " << jugadores[i].numFallos << endl;
    }
    cout << "==================================\n\n";

    cout<<"Ingrese cualquier caracter para salir: ";
    cin>>regresar;
    system("cls");
    }
}

void menu_rondas(){
    bool finalizar_menu = false;//Para romper el loop

    while (!finalizar_menu){
        cout<<"Inserte las rondas para el juego (1-5): ";
        cin>>rondas;//Se insertan las rondas

        if (rondas < 1 || rondas > 5){
            cout<<"Numero invalido de rondas, intente nuevamente\n";//el numero es menor que 1 o mayor a 10
        }

        else{
            finalizar_menu = true;//Si el numero de rondas es valido entonces se cierra el loop
        }
    }

    system("cls");
    
}

int agregarJugadores() {
    bool num_jugadores_insertado = false;//Variable para finalizar el menu

    while (!num_jugadores_insertado){//mientras no se hayan insertado numero de jugadores
        cout<<"Cuantos jugadores deseria agregar (1-4): ";
        cin>>numjugadores;//Se insertan el numero de jugadores

        if (numjugadores < 1 || numjugadores > 4){
            cout<<"Valor invalido, vuelva a ingresar";//Si no esta entre los parametros pide de nuevo
        }

    else{
        break;
        }   
    }

    cout<<"Inserte el/los nombres de los jugadores\n";

    for (int i = 0; i < numjugadores; i++){
        cout<<"Jugador "<<i+1<<": ";//Se insertan los nombres de los jugadores
        cin>>jugadores[i].nombre;
    }

    system("cls");
}

void ver_jugadores(){
    for (int i = 0; i < numjugadores; i++){
        cout<<"Jugador "<<i+1<<": "<<jugadores[i].nombre<<"\n";//Con el for se muestra cada jugador
    }
    
    cout<<"Ingrese cualquier caracter para salir: ";
    cin>>regresar;
    system("cls");

    menuJuego();
}

int menuAyuda(){
    
    //Permite volver al menu principal al mostrar las instrucciones  
    cout << "COMO JUGAR AHORCADO: " << endl << endl; 
    cout << " (1) El juego elige una palabra al azar dependiendo del nivel de dificultad seleccionado" << endl; 
    cout << " (2) El jugador va llenando los espacios con cada letra de la palabra" << endl; 
    cout << " (3) Si la letra introducida se encuentra en la palabra, se llenara el espacio y se mostrara en la posicion correcta" << endl; 
    cout << " (4) Si la letra introducida no se encuentra en la palabra, se dibujara una parte del ahorcado" << endl; 
    cout << " (5) Se permite introducir solo seis letras incorrectas, despues de esto el dibujo del ahorcado se completa" << endl; 
    cout << " (6) El juego finaliza cuando se llena la palabra o se completa el dibujo del ahorcado" << endl;
    cout << " (7) El ganador se determina hasta finalizar la cantidad de rondas seleccionadas" << endl; 
    cout << " (8) Los fallos se van acumulando al ingresar una letra incorrecta" << endl; 
    cout << " (9) El jugador que tenga menos fallos es el ganador del juego" << endl << endl; 
    
    cout << "Ingrese cualquier caracter para salir: "; 
    cin >> regresar;
    system("cls");
}

int mostrarIntegrantes(){
    int num; 
    bool volverMenu = false; 
    cout << endl; 
    cout << "INTEGRANTES DEL PROYECTO: " << endl << endl; 
    cout << "Leonardo Sebastian Molina Santos 00161024" << endl; 
    cout << "Fernando Josue Escamilla Rivera 00053324" << endl; 
    cout << "Kristen Nicole Cruz Rodriguez 00051524" << endl << endl;

    cout << "Ingrese cualquier caracter para salir: "; 
    cin >> regresar; 
    system("cls");
}

int salir(){
    cout << "Gracias por jugar ahorcado!" << endl; 
}

int menu_dificultad(){

    int dificultad;
    bool dificultad_correcta = false;


    while (!dificultad_correcta)
    {
        cout<<"DIFICULTAD\n\n";
        cout<<"[1] Facil\n";
        cout<<"[2] Normal\n";
        cout<<"[3] Dificil\n";
        cout<<"Elija la dificultad: ";
        cin >> dificultad; 
        system("cls");

        if (dificultad < 1 || dificultad > 3){
            cout<<"Por favor inserte un valor adecuado\n";
        }

        else{
            dificultad_correcta = true;
        }
    }

    return dificultad;
}

void Juego_Principal() {

    menu_rondas();

    for (int i = 0; i < rondas; i++){
        //se decide la dificultad de la ronda 
        int dificultad = menu_dificultad();
        //Palabra a seleccioar para la ronda
        string palabra = seleccion_palabra(dificultad);
        //Numero de caracteres de la palabra
        int num_caracteres_palabra = palabra.size();
        //variable que se usara para lo visual y comparacion
        string mostrar;
        //Letra que insertara el jugador
        char letra;

        //Fallos totales del juego
        int fallos = 0;
        //Variables para confirmar si la letra es correcta y si la palabra descubierta esta completa 
        bool letra_correcta = false;
        bool palabra_completa = false;

        for (int i = 0; i < num_caracteres_palabra; i++){//Primero haremos la palabra oculta guiones bajos
            mostrar[i] = '_';
        }

        cout<<"        RONDA "<<i+1<<endl;

        while (fallos <= 5 && !palabra_completa){//mientras los fallos sean menos que seis y la palabra no este completa

            for (int i = 0; i < numjugadores; i++){
            //La confirmacion de letra correcta se vuelve falsa para seguir el bucle
            letra_correcta = false;
            //Lo que el jugador vera

            for(int i = 0; i < numjugadores; i++){
                cout << "     " <<jugadores[i].nombre << ": " << jugadores[i].numFallos << " fallos"; 
                cout << endl; 
            }

            cout<<"========AHORCADO========\n";
            cout<<"    turno de: "<<jugadores[i].nombre<<"\n";
            dibujo_ahorcado(fallos);
            cout<<endl;

            for (int i = 0; i < num_caracteres_palabra; i++){
                cout<<mostrar[i]<<" ";
            }

            cout<<endl;
            //el jugador insertara la letra
            cout<<"Inserte la letra: ";
            cin>>letra;
            system("cls");

            for (int i = 0; i < num_caracteres_palabra; i++){//for para verificar si la letra se igual a alguna letra en la palabra
                
                if (letra == palabra[i]){//Si lo es se mostrara la letra insertada
                    mostrar[i] = letra;
                    letra_correcta = true;//La confirmacion de letra correcta se vuelve verdadera
                }
            }

            if (letra_correcta == false){//Si la confirmacion de letra correcta es falsa
                fallos++;//Los fallos totales aumentan
                jugadores[i].numFallos++;//Los fallos del jugador aumentan
            }
            
            int espacios_guiones = 0;//Variable para verificar si la palabra esta completa

            for (int i = 0; i < num_caracteres_palabra; i++){

                if (mostrar[i] == '_'){//Si existen guiones en la palabra a mostrar los espacios con  guiones aumentan
                    espacios_guiones++;
                }
                
            }

            if (espacios_guiones == 0){
                palabra_completa = true;//Si no existen guiones entonces el loop termina
                break;
            }

            if (fallos > 5 || palabra_completa == true){
                break;
            }
            
            }

            if (fallos > 5 || palabra_completa == true){
                break;
            }
    }

    switch (palabra_completa){
        case 1:
            cout<<"PALABRA ACERTADA\n";

            for (int i = 0; i < num_caracteres_palabra; i++){
                cout<<palabra[i];
            }
            
            break;

        case 0://Pierden la ronda
            cout<<"     RONDA FALLADA :(\n";

            dibujo_ahorcado(fallos);

            cout<<"\nLa palabra correcta era: ";
            
            for (int i = 0; i < num_caracteres_palabra; i++){
                cout<<palabra[i];
            }
            break;
        }
        
        cout<<"\n\nIngrese cualquier caracter para continuar: ";
        cin>>regresar;
        system("cls");
    }
    pantallafinal();
    

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
    string palabra_dificil[10]={"computadoras","perplejidad","ovoviviparo","universitarios","paralelepipedo","programacion","refraccion","cardiologia","caleidoscopio","desencadenante"};

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