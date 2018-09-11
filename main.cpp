/* Practica de Laboratorio 2
*  Informatica 2 - 2018_2
*  Prof: Juan Camilo Correa Chica
*  Fecha: Agosto 27/2018 - Septiembre 3/2018
*  Plazo máximo para enviar enlace para clonar el repositorio: NO definido aun
*  Estudiante1: César Camilo Correa Cardona
*  Fecha del ultimo Commit en GitHub: Agregue la fecha y hora del ultimo Commit (aproximada)
*
* 1. Declare una estructura global con 6 miembros de distinto tipo y en este orden (con sus miembros inicializados):
* int
* char
* float
* char
* double
 * int
 */

/* Declare otra estructura global con 6 miembros de distinto tipo y en este orden (con sus miembros inicializados):
 * int
 * int
 * float
 * char
 * char
 * double
 */

//Declare punteros a cada una de las estructuras e imprima en pantalla el valor de sus miembros haciendo uso
//del operador ->
//Luego imprima de nuevo el valor de los miembros de la estructura pero esta vez haga uso de "type casting",
//operadores y aritmetica de punteros
//Calcule el tamaño de cada estructura con la funcion sizeof() y explique en un comentario sus observaciones
//acerca del resultado obtenido respecto a los tamanios de las estructuras

/*2. Diseñe una funcion llamada foo_function() que debe tener un arreglo unidimensional del tipo y del tamanio que ud prefiera.
 * Declare un puntero al arreglo y luego agregue las lineas de codigo necesarias para lograr que cada vez que
 * se haga un llamado a la funcion foo_function() desde de la funcion main se imprima un elemento distinto del arreglo
 * (en el orden que estan en el arreglo) con ayuda de la aritmetica de punteros.
 */

 /*3. Diseñe un menu de inicio para un programa de calculo sencillo. En el menu se debe preguntar por un numero de opcion
  * y cada numero de opcion debe ejecutar una funcion que hace un calculo matematico distinto. Todas las funciones deben
  * recibir un argumento tipo float y un valor de retorno idem. El menu debe realizarse utilizando SOLAMENTE punteros a funciones.
  * Bajo NINGUN motivo puede realizarlo utilizando sentencias "if..else if..else" o "switch..case"
  */
/* Enlaces de internet utiles:
 * http://c.conclase.net/curso/index.php?cap=011
 * http://c.conclase.net/curso/index.php?cap=011b#STR_sizeof
 * https://stackoverflow.com/questions/8657776/pointer-arithmetic-with-structures
 * https://stackoverflow.com/questions/119123/why-isnt-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member
 * http://www.catb.org/esr/structure-packing/
 * https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
 * https://barrgroup.com/Embedded-Systems/How-To/C-Function-Pointers
 */

#include <iostream>

using namespace std;

void primerPunto();
void segundoPunto();
void tercerPunto();
void foo_funtion();
int temp=0;

struct myStruct{
    int  a = 7;
    char b = 'a';
    float c = 33;
    char  d = 'b';
    double e = 24.2;
    int f = 2;

};

struct otraStructura{
    int a = 8;
    int b = 9;
    float c = 10;
    char d = 'h';
    char e = 'f';
    double f = 11.12;
};

static myStruct estructura1;
static otraStructura estructura2;

int main()
{
    int opc = 9;
    do {
    cout<<endl<<"### LAB2 Informatica 2 ###"<<endl;
    cout<<"Cual punto desea revisar?: "<<endl;
    cout<<"1. Punto #1"<<endl;
    cout<<"2. Punto #2"<<endl;
    cout<<"3. Punto #3"<<endl;
    cout<<"0. Para salir...."<<endl;
    cin>>opc;
    if (opc==1) primerPunto();
    if (opc==2) segundoPunto();
    if (opc==3) tercerPunto();
    } while (opc!=0);
    return 0;
}

void primerPunto(){
    myStruct *apuntador1 = &estructura1;

    cout<<endl<<"Los datos contenidos en la estructura 1 son: "<<endl;

    cout<<endl<<"### Haciendo uso del operador -> ###"<<endl;

    cout<<endl<<"El int a: "<<apuntador1->a<<endl;

    cout<<"El char b: "<<apuntador1->b<<endl;

    cout<<"El float c: "<<apuntador1->c<<endl;

    cout<<"El char d: "<<apuntador1->d<<endl;

    cout<<"El double e: "<<apuntador1->e<<endl;

    cout<<"El int f: "<<apuntador1->f<<endl;

    cout<<endl<<"### Haciendo uso de type casting, operadores y arimetica de punteros ###"<<endl;

    cout<<endl<<"El int a: "<<*((int*)apuntador1)<<endl;

    cout<<"El char b: "<<*((char*)apuntador1+4)<<endl;

    cout<<"El float c: "<<*((float*)apuntador1+2)<<endl;

    cout<<"El char d: "<<*((char*)apuntador1+12)<<endl;

    cout<<"El double e: "<<*((double*)apuntador1+2)<<endl;

    cout<<"El int f: "<<*((int*)apuntador1+6)<<endl;

    cout<<endl<<"El tamanio de la estructura myStruct es: "<<sizeof(myStruct)<<endl;

    //El tamanio de la estructura es 32 pero tiene algunos bytes sin uso, debido al orden de los elementos de la
    //estructura al final, se reserva un bloque vacio de 4 bytes debido a la existencia de una variable del tipo double
    //en la estructura.

    otraStructura *apuntador2 = &estructura2;

    cout<<endl<<"Los datos contenidos en la estructura 2 son: "<<endl;

    cout<<endl<<"### Haciendo uso del operador -> ###"<<endl;

    cout<<endl<<"El int a: "<<apuntador2->a<<endl;

    cout<<"El int b: "<<apuntador2->b<<endl;

    cout<<"El float c: "<<apuntador2->c<<endl;

    cout<<"El char d: "<<apuntador2->d<<endl;

    cout<<"El char e: "<<apuntador2->e<<endl;

    cout<<"El double f: "<<apuntador2->f<<endl;

    cout<<endl<<"### Haciendo uso de type casting, operadores y arimetica de punteros ###"<<endl;

    cout<<"El int a: "<<*((int*)apuntador2)<<endl;

    cout<<"El int b: "<<*((int*)apuntador2+1)<<endl;

    cout<<"El float c: "<<*((float*)apuntador2+2)<<endl;

    cout<<"El char d: "<<*((char*)apuntador2+12)<<endl;

    cout<<"El char e: "<<*((char*)apuntador2+13)<<endl;

    cout<<"El double f: "<<*((double*)apuntador2+2)<<endl;

    cout<<endl<<"El tamanio de la estructura otraStructura es: "<<sizeof(otraStructura)<<endl;

    //El tamanio de la estructura es 24 pero tiene algunos bytes sin uso, debido al orden de los elementos de la
    //estructura al final, como tenemos dos varibles char continuas ellas ocupan dos bytes continuos de un mismo bloque.

    /*    cout<<"El tamanio de int es: "<<sizeof(int)<<endl;
    cout<<"El tamanio de char es: "<<sizeof(char)<<endl;
    cout<<"El tamanio de float es: "<<sizeof(float)<<endl;
    cout<<"El tamanio de double es: "<<sizeof(double)<<endl;
    cout<<"El tamanio de String es: "<<sizeof(string)<<endl;
*/

    system("pause");
    system("cls");

}

void foo_function(){
    string arreglo[10]={"Primero","Segundo","Tercero","Cuarto","Quinto","Sexto","Septimo","Octavo","Noveno","Decimo"};
    string *puntero = arreglo;
    cout<<endl<<"El elemento en la posicion "<<temp+1<<" es: "<<puntero[temp];
    temp++;
}

void segundoPunto(){

    for(int i=0; i<10; i++){
        foo_function();
    }
    cout<<endl;
    system("pause");
    system("cls");
}

void tercerPunto(){
    cout<<"Acuerdese de implementar este punto mk!"<<endl;
}
