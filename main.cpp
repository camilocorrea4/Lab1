#include <iostream>
#include <vector>
#include <string>
#include "pelicula.h"

using namespace std;

void calificarPeliculas();

vector<Pelicula> movies;
int main()
{
    int opt = 9890;
    Pelicula control;

    do {
        cout << "### Bienvenido a LABFLIX ####" << endl;
        cout << "Roten Tomatoes nos quedo chiquito!!!" << endl;
        cout << "Elija una opción: " << endl;
        cout << "1. Para calificar una pelicula." << endl;
        cout << "2. Recomiendame una pelicula. " << endl;
        cout << "3. Para Salir. " << endl;
        cin >> opt;
        switch (opt) {
            case 1:{
            int id;
            char *t1, *t2, *t3;
            float r;
            if(control.consultarCalificacion()==0){
                cout<<"Aun no se ha calificado ningna pelicula, vamos a ingresar la primera. "<<endl;
                cout<<"Por favor digite el id de la pelicula: "<<endl;
                cin>>id;
                cout<<"Por favor digite el Nombre de la pelicula: "<<endl;
                cin>>t1;
                cout<<"Por favor digite el Genero de la pelicula: "<<endl;
                cin>>t2;
                cout<<"Por favor digite el nombre del Director de la pelicula: "<<endl;
                cin>>t3;
                cout<<"Por favor digite la calificacion de la pelicula: "<<endl;
                cin>>r;
            }
            break;
            }
        default:
            cout<<"Opcion incorrecta por favor intente de nuevo. "<<endl;
}
        return 0;
} while (opt!=3);
}
