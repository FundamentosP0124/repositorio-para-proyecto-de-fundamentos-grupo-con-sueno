#include<iostream>
#include<time.h>
#include<random>
#include<conio.h>
#include<string.h>

using namespace std;

//Asignar un numero aleatorio entre 1 y 5 para las palabras de cada dificultad
int numero_aleatorio();

//Funcion para elegir la palabra dependiendo de la dificultad elegida por el usuario
string seleccion_palabra(int x);

//Funcion para sacar el numero de caracteres de la palabra escogida
int numero_caracteres(int x);

int main(){
    int opcion = 0;
    int numero_fallos = 0;
    bool letra_correcta = false;
    bool palabra_completa = false;

    cin>>opcion;

    cout<<seleccion_palabra(opcion)<<endl;
    cout<<"El numero de caracteres de la palabra es: "<<numero_caracteres(opcion);
    

    return 0;
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

    return palabra;
}

int numero_caracteres(int x){
    int num_caracteres = 0;

    for ( int i = 0; seleccion_palabra(x)[i]; i++)
    {
        num_caracteres++;
    }

    return num_caracteres;
}
