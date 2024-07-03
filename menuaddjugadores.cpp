#include <iostream>
using namespace std;
const int MAX_JUGADORES=4;
struct jugador{
      string nombre;
      int numFallos;
};
jugador jugadores[MAX_JUGADORES];
int addjugadores(){
    int n;
    do
    {
        cout<<"cuantas personas van a jugar? max 4";
        cin>> n;
        if(n<1|| n> MAX_JUGADORES){
            cout<<"numero de jugadores no valido. intente otra vez""\n";
        }
    } while (n<1||n>MAX_JUGADORES);

    for(int i=0; i<n; i++ ){
        cout<<"agregue el nombre del jugador "<<(i+1)<<": ";
        cin>>jugadores[i].nombre;
        jugadores[i].numFallos=0;
    }
    cout<<"jugadores agregados:"<<"\n";
    for(int i=0;i<n;i++){
        cout<<"Jugador "<<i+1<<": "<<jugadores[i].nombre<<"\n";

    }
    return n;
}
