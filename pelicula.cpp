#include "pelicula.h"

using namespace std;

Pelicula::Pelicula()
{

}

Pelicula::Pelicula(int _id, char *_nombre, char *_genero, char *_director, float _rating)
{
    id = _id;
    nombre = _nombre;
    genero = _genero;
    director = _director;
    modificarRating(_rating);
}

Pelicula::Pelicula(Pelicula &movie)
{
    id = movie.id;
    nombre = movie.nombre;
    genero = movie.genero;
    director = movie.director;
    rating = movie.rating;
}

void Pelicula::modificarId(int _id)
{
    id = _id;
}

void Pelicula::modificarNombre(char *_nombre)
{
    nombre = _nombre;
}

void Pelicula::modificarGenero(char *_genero)
{
    genero = _genero;
}

void Pelicula::modificarDirector(char *_director)
{
    director = _director;
}

void Pelicula::modificarRating(float _rating)
{
    rating += _rating;
    calificada++;
    calcularPromedio();
}

void Pelicula::calcularPromedio()
{
    promedio=rating/calificada;
}

int Pelicula::consultarID()
{
    return id;
}

char* Pelicula::consultarNombre()
{
    return nombre;
}

char* Pelicula::consultarGenero()
{
    return genero;
}

char* Pelicula::consultarDirector()
{
    return director;
}

float Pelicula::consultarRating()
{
    return promedio;
}

int Pelicula::consultarCalificacion()
{
    return calificada;
}
