#include "libro.h"

using namespace std;

libro::libro()
{

}

libro::libro(int _c, string _n, char _m, string _a, bool _d)
{
    codigo= _c;
    nombre= _n;
    materia= _m;
    autor= _a;
    disponibilidad= _d;

}

void libro::modificarCodigo(int _a)
{
    codigo= _a;
}

int libro::obtenerCodigo()
{
    return codigo;
}

void libro::modificarNombre(string _n)
{
    nombre= _n;
}

string libro::obtenerNombre()
{
    return nombre;
}

void libro::modificarMateria(char _m)
{
    materia= _m;
}

char libro::obtenerMateria()
{
    return materia;
}

void libro::modificarAutor(string _autor)
{
    autor= _autor;
}

string libro::obtenerAutor()
{
    return autor;
}

void libro::modificarDisponibilidad(bool _d)
{
    disponibilidad= _d;
}

bool libro::obtenerDisponibilidad()
{
    return disponibilidad;
}


bool amiga::disponible(libro &l)
{
    if(l.disponibilidad==true){
        return true;
    } else {
        return false;
    }
}
