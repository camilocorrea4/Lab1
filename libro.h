#ifndef LIBRO_H
#define LIBRO_H
#include <string>

using namespace std;

class libro
{
    int codigo;
    string nombre;
    char materia;
    string autor;
    bool disponibilidad;

public:
    friend void famiga(libro&);
    friend class amiga;
    libro();
    libro(int _c, string _n, char _m, string _a, bool _d);
    void modificarCodigo(int _a);
    int obtenerCodigo();
    void modificarNombre(string _n);
    string obtenerNombre();
    void modificarMateria(char _m);
    char obtenerMateria();
    void modificarAutor(string _autor);
    string obtenerAutor();
    void modificarDisponibilidad(bool _d);
    bool obtenerDisponibilidad();
};

class amiga
{
public:
    bool disponible(libro& l);
};

#endif // LIBRO_H
