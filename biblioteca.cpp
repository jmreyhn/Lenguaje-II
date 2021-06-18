#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

string libros[15][3];

void cargarLibros() {
    // Arreglo con categoria, descripcion y autor(es)
	libros[0][0] = "Aventuras"; libros[0][1] = "Luigi vs Bowser"; libros[0][2] = "Carlos Centeno, Mario Perdomo";
	libros[1][0] = "Aventuras"; libros[1][1] = "Mario y el fin del universo"; libros[1][2] = "Arnold Toro";
	libros[2][0] = "Aventuras"; libros[2][1] = "Mario y sus amigos"; libros[2][2] = "Agustin Lara, Maria Matute";
	libros[3][0] = "Deportes"; libros[3][1] = "Los 10 mandamientos del futbol"; libros[3][2] = "Luis Rapalo";
	libros[4][0] = "Deportes"; libros[4][1] = "El origen de los deportes"; libros[4][2] = "Marlon Ramirez, Erick Norales, Dunia Chavez";
	libros[5][0] = "Deportes"; libros[5][1] = "Deportes extremos: ventajas y desventajas"; libros[5][2] = "Marcos Ramirez";
	libros[6][0] = "Deportes"; libros[6][1] = "Los juegos olimpicos a traves del tiempo"; libros[6][2] = "Alicia Rodas, Hector Funez";
	libros[7][0] = "Deportes"; libros[7][1] = "Memorias de futbolistas"; libros[7][2] = "Sara Restrepo";
	libros[8][0] = "Juegos"; libros[8][1] = "La evolucion de los videojuegos"; libros[8][2] = "Oscar Peña";
	libros[9][0] = "Juegos"; libros[9][1] = "Los 50 mejores videojuegos de todos los tiempos"; libros[9][2] = "Luis Rapalo, Karina Fuentes";
	libros[10][0] = "Juegos"; libros[10][1] = "Ser Gamer; ¿La profesion del futuro?"; libros[10][2] = "Arnold Toro, Juan Guzman";
	libros[11][0] = "Juegos"; libros[11][1] = "Los videojuegos y la vida social"; libros[11][2] = "Karen Fernandez";
	libros[12][0] = "Musica"; libros[12][1] = "Como empezar a escribir una cancion desde cero"; libros[12][2] = "Carlos Ortiz, Gabriel Castillo";
	libros[13][0] = "Musica"; libros[13][1] = "Como leer una partitura"; libros[13][2] = "Sebastian Obando";
	libros[14][0] = "Musica"; libros[14][1] = "Como influye la musica en las personas"; libros[14][2] = "Sofia Ponce, Carlos Ruiz";
}


int main(int argc, char const *argv[])
{
    cargarLibros();

    srand (time(NULL));
    
    bool salir = false;

    while (salir == false)
    {
        string buscar = "";
        system("cls");
        cout << "Ingrese la descripcion o autor del libro que busca: ";
        cin >> buscar;

        // busqueda
        for (int i = 0; i < 15; i++)
        {
            string libro = libros[i][1];
            string libroEnminuscula = libro;
            string autor = libros[i][2];
            string autorEnminuscula = autor;
            // transformamos a minuscula los string buscar, libro y autor
            transform(libroEnminuscula.begin(), libroEnminuscula.end(), libroEnminuscula.begin(), ::tolower);
            transform(autorEnminuscula.begin(), autorEnminuscula.end(), autorEnminuscula.begin(), ::tolower);
            transform(buscar.begin(), buscar.end(), buscar.begin(), ::tolower);

            if (libroEnminuscula.find(buscar) && (autorEnminuscula.find(buscar) != string::npos)){   
                cout << "Libro encontrado: " << libro << endl;

                cout << "Tambien te sugerimos estos libros: " << endl;

                int sugerencia1 = rand() % 14 + 1;
                int sugerencia2 = rand() % 14 + 1;
                int sugerencia3 = rand() % 14 + 1;

                cout << " Sugerencia 1: " << libros[sugerencia1][1] << endl;
                cout << " Sugerencia 2: " << libros[sugerencia2][1] << endl;
                cout << " Sugerencia 3: " << libros[sugerencia3][1] << endl;

                salir = true;
                break;
            } 
        }
    

        if (salir == false) {
            char continuar = 'n';

            while(true) {
                system("cls");
                cout << "No se encontro el libro que busca. Desea continuar? s/n ";
                cin >> continuar;

                if (continuar == 's' || continuar == 'S') {
                    break;
                } else if (continuar == 'n' || continuar == 'N') {
                    salir = true;
                    break;
                }
            }
        }
    }
    

    return 0;
}