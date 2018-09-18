/*2. Diseñe e implemente una clase llamada "Movie" que tiene los siguientes atributos privados:
* Un atributo de tipo entero para el ID de la pelicula
* Un atributo de tipo cadena de caracteres para el nombre de la pelicula
* Un atributo de tipo cadena de caracteres para el genero de la pelicula
* Un atributo de tipo cadena de caracteres para el director de la pelicula
* Un atributo tipo float para el "rating promedio" de la pelicula (el rating es un valor de 0.0 a 5.0 con el que los cinefilos califican una pelicula)
* Un atributo tipo int que almacena el número de veces que la pelicula ha sido calificada
*
* El "rating promedio" de una pelicula se calcula como el total de la suma de todas las calificaciones que se le han dado a una pelicula
* sobre el numero de calificaciones.
*
* La clase debe contar con un constructor por defecto, un constructor para inicializar atributos al instanciar objetos de la clase y un
* constructor por copia.
* La clase debe contar con metodos para modificar y obtener el valor de cada atributo individualmente.
*
* 3. Utilizando la clase que acaba de implementar, diseñe una pequeña aplicacion que permite a un usuario calificar peliculas. Si la pelicula ya ha sido calificada previamente (es decir,
* si ya existe en la base de datos) entonces debe pedirle al usuario una calificación de 0.0 a 5.0 para esa pelicula. Si la pelicula no está
* en la base de datos, entonces el programa debe permitirle al usuario ingresar la nueva pelicula a la base de datos, con el diligenciamiento
* de todos sus datos, incluida la calificación de la pelicula por supuesto.
*
* La aplicación debe tener una opcion que sirve para recomendar peliculas a los usuarios. Esta recomendación se debe hacer de acuerdo a la
* popularidad y a la calificación de la pelicula. Es decir, se deben recomendar las peliculas con las calificaciones más altas y con el
* mayor número de calificaciones recibidas, osea que no tiene sentido recomendar una pelicula que ha sido calificada con 5.0 pero tiene
* una sola calificación de un aficionado al cine.
*/
#ifndef PELICULA_H
#define PELICULA_H


using namespace std;
class Pelicula
{
    int id;
    char *nombre;
    char *genero;
    char *director;
    float rating=0.0f;
    float promedio=0.0f;
    int calificada=0;
public:
    Pelicula();
    Pelicula(int _id, char *_nombre, char *_genero, char *_director, float _rating);
    Pelicula(Pelicula &movie);
    void modificarId(int _id);
    void modificarNombre(char *_nombre);
    void modificarGenero(char *_genero);
    void modificarDirector(char *_director);
    void modificarRating(float _rating);
    void calcularPromedio();
    void ponerCalificacion(int _cal);

    int consultarID(void);
    char* consultarNombre(void);
    char* consultarGenero(void);
    char* consultarDirector(void);
    float consultarRating(void);
    int consultarCalificacion(void);
};

#endif // PELICULA_H
