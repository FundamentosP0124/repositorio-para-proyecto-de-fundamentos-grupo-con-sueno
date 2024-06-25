#include<iostream>
#include<time.h>
#include<random>
#include<conio.h>

using namespace std;

//Asignar un numero aleatorio entre 1 y 5 para las palabras de cada dificultad
int numero_aleatorio();

//Funcion para elegir la palabra dependiendo de la dificultad elegida por el usuario
string seleccion_palabra(int x);

int main(){

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

