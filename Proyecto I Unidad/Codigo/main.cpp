#include <iostream>
#include "startShip.h"
#include "snake.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int numero = 0;
    system("cls");

    cout << "**************";
    cout << endl;
    cout << "MENU DE JUEGOS"; 
    cout << endl;
    cout << "**************";
    cout << endl;
    cout << endl;
    cout << "Seleccione un juego" << endl;
    cout << "1 - StarShip" << endl;
    cout << "2 - Snake" << endl;
    cout << "Ingrese un numero del menu para seleccionar juego: ";
    cin >> numero;
    cout << endl;

    switch (numero)
        {
        case 1: 
            starShip();            
            break;
        case 2:
            snake();
            break;


        default:
            break;
        }


    return 0;
}
