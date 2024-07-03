#include<iostream>
#include<time.h>
#include<random>
#include<conio.h>
#include<string.h>
using namespace std;
struct jugadores
{
    string jugador1;
    int fallosjugador1;
    string judador2;
    int fallosjugador2;
    string jugador3;
    int fallosjugador3;
    string jugador4;
    int fallosjugador4;
}jugad[4];


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

void menu_dificultad();

//Funcion para seleccionar un numero aleatorio entre 0 y 9
int numero_aleatorio();

//Funcion para seleccionar una palabra aleatoria dependiendo de la dificultad
string seleccion_palabra(int diff);

//Funcion del juego del ahorcado
void Juego_Principal();

int main(){
    int opcion; 
    
    //Se repite mientras la opcion no sea igual a 4 (salir)
    while(opcion != 4){
        menuPrincipal(); 
        cin >> opcion; 

        switch(opcion){
        case 1: 
           /* Menu antes de empezar el juego

           1. asignar jugadores
           2. ver jugadores

           luego pediria el numero de rondas

           comienza el juego */

           Juego_Principal();
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
cout << "=================" << endl;
cout << "     AHORCADO    " << endl; 
cout << "=================" << endl; 
cout << "1. Comenzar a jugar" << endl; 
cout << "2. Mostrar menu de ayuda" << endl; 
cout << "3. Mostrar integrantes del proyecto" << endl; 
cout << "4. Salir" << endl;
cout << "Seleccione una opcion: "; 
}


int comenzarJuego(){
    void juegoPrincipal(); 
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
    cout << "Sebastian Leonardo Molina Santos 00161024" << endl; 
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

void Juego_Principal(){
    //Variables de la palabra a adivinar
    string palabra = seleccion_palabra(2);
    int num_characteres_palabra = palabra.size();
    //La palabra/guiones que se mostraran en pantalla
    string mostrar;
    //Letra que introducira el jugador
    char letra;
    //numero de fallos en el juego
    int fallos = 0;
    //Variables para confirmar si la palabra esta completamente adivinada y si la letra insertada es correcta
    bool palabra_completa = false;
    bool letra_correcta = false;
    int num; 
    bool volverMenu = false; 

    while(!volverMenu){
    
    cout << endl << endl; 
    cout << "     AHORCADO      " << endl; 
    cout << "Turno de: " << endl << endl; 
        cout<<"    +---+ \n";
        cout<<"        | \n";
        cout<<"        | \n";
        cout<<"        | \n";
        cout<<"        | \n";
        cout<<"        | \n";
        cout<<"   ======";
        cout << endl; 
        
    for (int i = 0; i < num_characteres_palabra; i++){//se asignan guiones a los valores de mostrar
        mostrar[i] = '_';
    }
    
    while (fallos < 6 && !palabra_completa)//Mientras los fallos sean menores a 6 y la palabra no este completa
    {
        letra_correcta = false;//Letra correcta regresa a ser falso para continuar con el loop

        for (int i = 0; i < num_characteres_palabra; i++){
            cout<<mostrar[i]<<" ";
        }
        cout << endl; 
        cout << "Ingrese la letra: "; 
        cin>>letra;

        for (int i = 0; i < num_characteres_palabra; i++){//verifica si la letra es igual a algun caracter de la palabra
            if (letra == palabra[i]){//si es igual
                mostrar[i] = letra;//El _ respectivo a esa posicion se vuelve la letra
                letra_correcta = true;//La letra existe en la palabra
            } 
        }
            
        if (letra_correcta == false){//Si la letra no existe en la palabra
            fallos++;//El numero de fallos aumenta
            //Subir numero de fallos del jugador aqui tambien
        }

        int espacios_vacios = 0;//Variable para verificar si la palabra fue completamente encontrada
        
        for (int i = 0; i < num_characteres_palabra; i++){//Verifica que la palabra esta sin guiones bajos

            if (mostrar[i] == '_'){//Si hay guiones los espacios se suman
                espacios_vacios++;
            }
        }
        
        if (espacios_vacios == 0){//Si no hay espacios vacios
            palabra_completa = true;//La palabra esta completa
        }
    }
//==================Pantalla que se mostrara dependiendo si se encontro o no la palabra==================

    if (fallos > 6){//No se encontro la palabra porque superaron el numero de fallos

        cout<<"La palabra correcta era: ";
        for (int i = 0; i < num_characteres_palabra; i++){//Se muestra la palabra
            cout<<palabra[i];
        }
        
    } else{//Si se encontro la palabra
        cout<<"La palabra correcta es: ";
        for (int i = 0; i < num_characteres_palabra; i++){//se muestra la palabra
            cout<<palabra[i];
        }
    }
    cout<<endl;//Salto de linea
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