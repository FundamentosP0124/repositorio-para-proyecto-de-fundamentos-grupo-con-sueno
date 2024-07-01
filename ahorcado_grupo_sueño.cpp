#include<iostream>
#include<time.h>
#include<random>
#include<conio.h>
#include<string.h>

using namespace std;

//Funcion para mostrar el menu principal
int menuPrincipal(); 

//Funcion para iniciar el juego de ahorcado
int comenzarJuego(); 

//Funcion para mostrar el menu de ayuda
int menuAyuda(); 

//Funcion para mostrar los integrantes del proyecto
int mostrarIntegrantes(); 

//Funcion para salir del juego
int salir(); 
 
//Asignar un numero aleatorio entre 1 y 5 para las palabras de cada dificultad
int numero_aleatorio();

//Funcion para elegir la palabra dependiendo de la dificultad elegida por el usuario
string seleccion_palabra(int x);

//Funcion para sacar el numero de caracteres de la palabra escogida
int numero_caracteres(string pal);

//Funcion que mostrara la palabra mientras se vaya descubriendo
void palabra_escribir(string show, string word);

bool comparar_mostrar_palabra(bool full_word, string show, string word);

void prueba();

int main(){
    int opcion; 
    
    //Se repite mientras la opcion no sea igual a 4 (salir)
    while(opcion != 4){
        menuPrincipal(); 
        cin >> opcion; 

        switch(opcion){
        case 1: 
           comenzarJuego(); //Se comienza el juego
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

    prueba(); 

    return 0;
}

//Opciones del menu principal del juego
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


int numero_aleatorio(){
    //Usando la hora del computador del usuario se saca el numero aleatorio
    int valor = time(0);
    srand(valor);
    //Ese numero se divide entre 5 (los arreglos comienzan desde 0) porque son 5 palabras por dificultad
    int asignar_palabra = rand() % 5;

    return asignar_palabra;
}

string seleccion_palabra(int x){
    //Variables de las palabras del juego y su dificultad
    string palabra_facil[5]={"juego","taxi","comida","redes","caida",};
    string palabra_normal[5]={"programacion","desinfectante","recolectar","mosquitos","escalofrios"};
    string palabra_dificil[5]={"electrocardiograma","transustanciacion","ovoviviparo","desacostumbradamente","lactovegetarianismo"};
    string palabra_maxdif="electroencefalografista";

    string palabra;
    //La funcion retorna la palabra dependiendo de la dificultad
    switch (x){
    case 1:
    //la dificultad elegida es facil
        palabra = palabra_facil[numero_aleatorio()];
        break;

    case 2:
        palabra = palabra_normal[numero_aleatorio()];
        break;

    case 3:
        palabra = palabra_dificil[numero_aleatorio()];
        break;

    case 4:
        palabra = palabra_maxdif;
        break;

    case 5:
        palabra = "Haz regresado al menu anterior";
        break;
    
    default:
        palabra = "Opcion incorrecta intente de nuevo";
        break;
    }
//retorna la palabra escogida al azar dependiendo de 
    return palabra;
}

int numero_caracteres(string pal){
    int num_caracteres = 0;

    for ( int i = 0; pal[i]; i++){
        num_caracteres++;
    }

    return num_caracteres;
}

void Comparar_letra(){
}

void prueba(){
    int opcion;
    opcion = 0;
    int fallos = 0;

    bool letra_correcta = false;
    bool palabra_correcta = false;

    const string palabra = "hola";
    string mostrar;
    char letra;

    for (int i = 0; i < 4; i++)
    {
        mostrar[i] = '_';
    }
    
    while (fallos < 6 && !palabra_correcta)//mientras los fallos sean menores a 6 y la palabra no este descubierta
    {
        for (int i = 0; i < 4; i++){
            cout<<mostrar[i]<<" ";
        }
        
        cin>>letra;//Jugador inserta la letra

        letra_correcta = false;//la variable de letra verdadera se resetea a falso para continuar con la comparación
        palabra_correcta = false;

        for (int i = 0; i < 4; i++){//loop para confirmar si la letra existe en la palabra a encontrar

            if (letra == palabra[i]){//la letra es igual a alguna letra de la palabra

                mostrar[i] = letra;//El guion bajo se cambia a la letra correcta
                letra_correcta = true;//Si en algun momento la letra coincide con una de la palabra esta variable se volvera verdad
            }
            
        }

//Si la letra no coincide con ninguna de la palabra original entonces se aumentan los fallos
        if (letra_correcta == false){
            fallos++;
            //aqui se aumentarian los fallos del jugador
        }

        for (int i = 0; i < 4; i++){

        if (mostrar[i] == palabra[i]){
            palabra_correcta = true;
        }

        else if (mostrar[i] != palabra[i]){
            palabra_correcta = false;
        }

        }

    }

    for (int i = 0; i < 4; i++)
    {
        cout<<mostrar[i]<<" ";
    }
    

    
}

int mostrarIntegrantes(){
    cout << "INTEGRANTES DEL PROYECTO: " << endl << endl; 
    cout << "Sebastian Leonardo Molina Santos 00161024" << endl; 
    cout << "Fernando Josue Escamilla Rivera 00053324" << endl; 
    cout << "Kristen Nicole Cruz Rodriguez 00051524" << endl; 
}


int salir(){
    cout << "¡Gracias por jugar ahorcado!" << endl; 
}
