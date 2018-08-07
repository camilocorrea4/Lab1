/* Practica de Laboratorio 1
*  Informatica 2 - 2018_2
*  Prof: Juan Camilo Correa Chica
*  Fecha: Agosto 6/2018
*  Plazo máximo para enviar enlace para clonar el repositorio: Agosto 7/2018 - 11:59 am
*  Estudiante1: Cesar Camilo Correa Cardona
*  Fecha del ultimo Commit en GitHub: Agosto 7/2018 - 11:49 am
*

*  Primera parte: 
*
*  Ejercicio 1: Cree una cuenta en GitHub, que va a utilizar por el resto del curso para presentar
*               sus trabajos de laboratotio de informatica 2. Si lo prefiere tambien descargue una 
*				aplicacion de escritorio para administrar sus repositorios. Una vez creada su cuenta		
*				cree un repositorio llamado Lab1 y agreguele un README file con una descripcion adecuada.
*
*
*  Ejercicio 2: Clone este archivo del GitHub de camilocorreaUdeA y agreguelo al branch "master" de 
*				su repositorio Lab1, a partir de alli trabajara en el siguiente ejercicio.
*
*
*  Ejercicio 3: Diseñe una estructura llamada "Calendario", que solo contiene un campo de bits de tipo 
*				unsigned short int para los componentes de la fecha: anio, mes y dia.
*				Diseñe una funcion llamada "checkDate" que reciba como parametro una estructura "Calendario"
*				esa funcion debe ser capaz de verificar cualquier error en la fecha que este guardada en la
*				estructura que le entra como parametro, es decir, debe verificar que el dia no sea mayor a 31
*				a 30, a 29 o 28 segun el mes, ni menor que 1. Que el mes no sea mayor a 12 ni menor que 1. El
*				anio es un numero entre 0 y 127, el anio 0 corresponde a 1990, luego el anio 2018 por ejemplo
*               corresponderia al anio 28. Tambien debe verificar si el anio es bisiesto, en ese caso Febrero
*               puede tener 29 dias (enlace sugerido: http://www.disfrutalasmatematicas.com/medida/anos-bisiestos.html)
*				La funcion debe retornar un valor booleano que indique si la fecha ingresada esta bien o mal.
*/

#include <iostream>
#include <locale.h>

using namespace std;

//Aqui se declaran las variables globales
static bool bisiesto=false;
static struct Calendario {
    unsigned short int anio:16;
    unsigned short int mes:8;
    unsigned short int dia:8;
} calendar;

static unsigned short anio=0;
static unsigned short mes=0;
static unsigned short dia=0;
//Aqui se declaran los prototipos de las funciones

bool checkDate(Calendario);

//bool esBisiesto(unsigned short a){
//    a=anio;
//    if (anio%4==0 && (anio%100!=0 || anio%400==0)){
//            return true;
//        } else {
//            return false;
//    }
//}

bool checkDate(Calendario){

    // Primero me aseguro de que todos los datos esten entre los rangos correctos
    // Entre 1 y 32 para los dias; Entre 1 y 12 para los meses; Entre 1990 y 20118 para el año
    if ((calendar.dia>0) && (calendar.dia<32) && (calendar.mes>0) && (calendar.mes<13) && (calendar.anio>1989) & (calendar.anio<2119))
    {
        // Aqui, separo los meses con 31 dias
        if (calendar.mes==1 || calendar.mes==3 || calendar.mes==5 || calendar.mes==7 || calendar.mes==8 || calendar.mes==10 || calendar.mes==12)
        {
            return true;
        } else {
          // Aqui, separo los meses con 30 dias
            if (calendar.mes==4 || calendar.mes==6 || calendar.mes==9 || calendar.mes==11){
                return true;
            } else {
                if (bisiesto==true && calendar.dia<30){
                    return true;
                } else {
                    if (calendar.dia<29){
                        return true;
                    } else {
                        return false;
                    }
                }

                }
              }
           } else {
        return false;
      }
}

int main()
{
    setlocale(LC_CTYPE, "Spanish");
    cout<<endl<<"##### COMPROBADOR DE FECHAS ########"<<endl;
    cout<<"Ingrese el dia: "<<endl;
    cin>>dia;
    calendar.dia=dia;
    cout<<"Ingrese el mes: "<<endl;
    cin>>mes;
    calendar.mes=mes;
    cout<<"Ingrese el año, recuerde que para este ejercicio va desde 0 hasta 127 "<<endl;
    cin>>anio;
    calendar.anio=anio+1990;

    if (calendar.anio%4==0 && (calendar.anio%100!=0 || calendar.anio%400==0)){
          bisiesto=true;
    }
    //Declarando una variable localecon
    bool verifica_fecha=false;

	//Aqui puede invocar su funcion

    verifica_fecha=checkDate(calendar);

    if(verifica_fecha){
        cout<<"La fecha "<<calendar.dia<<"/"<<calendar.mes<<"/"<<calendar.anio<<" es una fecha valida!"<<endl;
    } else {
        cout<<"La fecha "<<calendar.dia<<"/"<<calendar.mes<<"/"<<calendar.anio<<" NO es una fecha valida!"<<endl;
    }

    if(bisiesto){
        cout<<"Y el año es bisiesto!."<<endl;
    }

	return 0;
}


