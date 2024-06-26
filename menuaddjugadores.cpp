#include <iostream>
using namespace std;
int main()
{
    //declaracion de variables para ingresar jugadores por medio de un arreglo
    int n;
    string num [100];
    char letra; 
    //menu para agregar jugadores utilizando un do while para solo aceptar datos entre 1 y 4
     do
    {
    cout<<"Bienvenido al juego de ahorcados""\n";
    cout<<"cuantos jugaran(maximo 4).""\n";
    cin>>n;   
     if(n>4||n<1){
        cout<<"datos incorrectos, el maximo es de 4 jugadores""\n";
    }
     } while (n>4||n<1);
     //introducir datos de los jugadores con un for, segun el numero de jugadores que se eligio antes
   
         for(int i=0; i<n; i++){
        cout<<"introduzca un nombre del jugador"<<i+1<<"\n";
        cin>>num[i];
       }
    //se muestra en pantalla los jugadores en orden 
    for(int j=0; j<n; j++){
    cout<<"El jugador"<<j+1<<"es""\n"<<num[j]<<"\n";
   }
   //se repite el turno hasta que se acierte la palabra.
    do
   {
   for(int k=0; k<n; k++){
  
    cout<<"turno del jugador"<<num[k]<<"\n""ingrese una letra""\n";
    cin>>letra;
   } 
   } while (code);
 
   
   
   
    
   


return 0; 
}