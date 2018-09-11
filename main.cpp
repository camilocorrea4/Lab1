#include <iostream>
#include <libro.h>

using namespace std;

int main()
{
    cout<<endl<<"### Laboratorio #3 ###"<<endl;
    return 0;
}

void famiga(libro &l){
    string nombre, autor;
    cout<<"Nombre del libro a buscar: "<<endl;
    cin>>nombre;
    cout<<"Nombre del autor del libro: "<<endl;
    cin>>autor;
    if(nombre==l.nombre && autor==l.autor)
        cout<<"Libro encontrado!."<<endl;

}
