#include <iostream>
using namespace std; 

int dibujo_ahorcado(int x);
int x; 

int main(){
  int dibujo_ahorcado(int x); 

  switch (x){
    case 0:
        cout<<" +---+ \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"======";
        break;

    case 1:
        cout<<" +---+ \n";
        cout<<" |   | \n";
        cout<<" O   | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"======";
        break;

    case 2:
        cout<<" +---+ \n";
        cout<<" |   | \n";
        cout<<" O   | \n";
        cout<<" |   | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"======";
        break;

    case 3:
        cout<<" +---+ \n";
        cout<<" |   | \n";
        cout<<" O   | \n";
        cout<<"/|   | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"======";
        break;

    case 4:
        cout<<" +---+ \n";
        cout<<" |   | \n";
        cout<<" O   | \n";
        cout<<"/|\\  | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"======";
        break;

    case 5:
        cout<<" +---+ \n";
        cout<<" |   | \n";
        cout<<" O   | \n";
        cout<<"/|\\  | \n";
        cout<<"  \\  | \n";
        cout<<"     | \n";
        cout<<"======";
        break;

        case 6:
        cout<<" +---+ \n";
        cout<<" |   | \n";
        cout<<" O   | \n";
        cout<<"/|\\  | \n";
        cout<<"/ \\  | \n";
        cout<<"     | \n";
        cout<<"======";
        break;

    default:
        break;
    }



}