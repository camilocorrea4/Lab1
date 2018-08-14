/* Practica de Laboratorio 1
*  Informatica 2 - 2018_2
*  Prof: Juan Camilo Correa Chica
*  Fecha: Agosto 6/2018 - Agosto 13/2018
*  Plazo máximo para enviar enlace para clonar el repositorio: Agosto 14/2018 - 09:29am
*  Estudiante1: Cesar Camilo Correa Cardona
*  Fecha del ultimo Commit en GitHub: Agosto 14/2018 - 1:38 am
*
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
*
*
*  Ejercicio 4: Un anagrama es una palabra que resulta de cambiar el orden de las letras de alguna otra palabra
*				por ejemplo: Maraca es un anagrama de Camara. Su tarea en este caso es diseñar una funcion que
*				identifique cuando una palabra es anagrama de otra. Su funcion debe recibir como parametros dos
*				arreglos constantes de tipo char y debe retornar un valor booleano que indica si los arreglos
*				ingresados son anagramas o no. Tips: 1. En caso de ser necesario, puede calcular la longitud de los
*				arreglos de entrada con la funcion strlen (http://www.cplusplus.com/reference/cstring/strlen/)
*				2. Recuerde que para un computador las letras o caracteres tienen una representacion numerica
*				en formato hexadecimal, puede verificarlo aqui: http://www.asciitable.com/ De acuerdo con eso
*				una forma facil de realizar su tarea podria ser sumando los caracteres de los arreglos y comparando
*				los resultados de las sumas para ambos arreglos. 3. Podria ser de utilidad ua funcion que convierte
*				todas las letras a minusculas, funcion tolower (http://www.cplusplus.com/reference/cctype/tolower/)
*				o a mayusculas, funcion toupper (http://www.cplusplus.com/reference/cctype/toupper/)
*
*
*  Ejercicio 5: En algunas aplicaciones es muy util poder tener a la mano una funcion que organice alfabeticamente
*				los caracteres (letras) de un arreglo, poniendo en primer lugar las mayusculas y luego las minusculas.
*				Agregue al programa una funcion que realice la tarea que se acabo de mencionar, dicha funcion debe recibir
*   			como parametro de entrada un arreglo de caracteres ("arreglo_desordenado") y debe organizarlo alfabeticamente.
*				No es necesario un valor de retorno, el resultado debe guardarse en el mismo "arreglo_desordenado". Tips: 1. En caso de
*				ser necesario, puede calcular la longitud del arreglo de entrada con la funcion strlen (http://www.cplusplus.com/reference/cstring/strlen/)
*				2. Recuerde que para un computador las letras o caracteres tienen una representacion numerica en formato hexadecimal,
*               puede verificarlo aqui: http://www.asciitable.com/ el valor aumenta de acuerdo al orden de las letras en el abecedario.
*
*
*  Ejercicio 6: En este ejercicio se debe construir una funcion que identifique si una palabra esta contenida dentro de una frase.
*				La funcion debe recibir dos parametros, que son los arreglos que contienen la plabra a buscar y el arreglo donde se va
*               a buscar. La funcion debe retornar un valor de tipo entero que indica la posicion del arreglo a partir de la que se encuentra
*               la palabra que se busca. Si no se encuentra entonces retorna cero. Tip: 1. Debe garantizar que la palabra que va a buscar no sea
*				mas grande (de mayor longitud) que el arreglo donde la va a buscar. 2. Recorra el arreglo de busqueda desde el primer elemento y
*               verifique que las letras de la palabra coinciden con las n (n = tamaño de la palabra a buscar) letras del arreglo de busqueda a partir
*               de la posicion en la que usted lo esta inspeccionando, ejemplo: si usted va en su recorrido del arreglo de busqueda en la posicion 6 y su
*               palabra a buscar es de 4 letras, entonces debe garantizar que las posiciones 6, 7, 8 y 9 del arreglo de busqueda coincieden con las
*               posiciones 0, 1, 2, 3 de la palabra que se esta buscando.
*/

#include <iostream>
#include <locale.h>
#include <string.h>
#include <ctype.h>


using namespace std;

//Aqui se declaran las variables globales

static char arreglo_desordenado[]="ugANMBpofJWMQZbbwktcynqidfgroc";

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
void ComprobarFecha();
void ComprobarAnagramas();
bool esAnagrama(char arreglo_1,char arreglo_2);
void Organizador(char organizar[]);
int Buscador(char p_a_buscar[],char array_busqueda[]);


int main()
{
    setlocale(LC_CTYPE, "Spanish");
    int opc=0;
    int index_busqueda=0;
    char p_a_buscar[] = "Informatica";
    char array_busqueda[] = "Bienvenidos a la primera practica del curso de Informatica 2 en el semestre 201_2";

    cout<<endl<<"##### EJERCICIOS LABORATORIO INFORMATICA II #######"<<endl;
    cout<<endl<<"Por favor elija una opción: "<<endl;
    cout<<"1. Para el verificador de fechas."<<endl;
    cout<<"2. Para el verificador de anagramas."<<endl;
    cout<<"3. Para el organizador alfabetico. "<<endl;
    cout<<"4. Para el buscador. "<<endl;
    cout<<"0. Para Salir..."<<endl;
    cin>>opc;
    switch (opc) {
    case 1:ComprobarFecha();break;
    case 2:ComprobarAnagramas();break;
    case 3:cout<<"Arreglo desordenado: "<<arreglo_desordenado<<endl;
           Organizador(arreglo_desordenado);
           cout<<"Arreglo ordenado: "<<arreglo_desordenado<<endl;break;
    case 4:index_busqueda = Buscador(p_a_buscar,array_busqueda);
           if(index_busqueda)
              cout<<"Palabra encontrada en la posicion: "<<index_busqueda<<endl;
           break;
    case 0:cout<<"Hasta la próxima"<<endl;;break;
    default:cout<<"Opción no valida"<<endl;
    }

    return 0;
}

bool checkDate(Calendario){

    // Verificar si el año es bisiesto.
    if (calendar.anio%4==0 && (calendar.anio%100!=0 || calendar.anio%400==0)){
          bisiesto=true;
    }

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

void ComprobarFecha(){
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

}

bool esAnagrama(char a1[],char a2[]){

    unsigned int i=0,j=0;
    for (i=0;a1[i]!='\0';i++){
        a1[i]=tolower(a1[i]);
    }

    for (j=0;a2[j]!='\0';j++){
        a2[j]=tolower(a2[j]);
    }

    if (strlen(a1) == strlen(a2)){
        unsigned int suma1 = 0;
        unsigned int suma2 = 0;
        i=0;

        for(i=0;i<=strlen(a1);i++){
            suma1 += a1[i];
        }
        j=0;
        for(j=0;j<=strlen(a2);++j){
            suma2 += a2[j];
        }

        if(suma1 == suma2){
            return true;
        } else {
            return false;
        }

    } else {
        return false;
    }

}

void ComprobarAnagramas(){
    char arreglo_1[] = "Amor";
    char arreglo_2[] = "Roma";

   bool son_anagramas;

   son_anagramas = esAnagrama(arreglo_1,arreglo_2);

   if(son_anagramas)
       cout<<"Los arreglos son anagramas!"<<endl;
   else
       cout<<"Los arreglos no son anagramas!"<<endl;

}

void Organizador(char organizar[]){
    char temp;
    unsigned int i=0,j=0,longitud;
    longitud=strlen(organizar);

        for (i=0;i<(longitud+1);i++){
            for (j=0;j<(longitud-1);j++){
                if (organizar[j]>organizar[j+1]){
                    temp = organizar[j];
                    organizar[j] = organizar[j+1];
                    organizar[j+1] = temp;
                }
            }
        }

}

int Buscador(char p_a_buscar[],char array_busqueda[]){
    unsigned int longbuscar=strlen(p_a_buscar);
    unsigned int longbusqueda=strlen(array_busqueda);

    if(longbuscar<=longbusqueda){
        int i = 0;
        unsigned int posicion;
        int exito=0;
        while (i < longbusqueda){
            if (p_a_buscar[0]==array_busqueda[i]){
                posicion=i;
                for(unsigned int j=0;j<=longbuscar;j++){
                    if (p_a_buscar[j]==array_busqueda[(i+j)])
                        exito ++;
                }
            }
            if (exito==longbuscar)
                return posicion;
            i++;
        }

    } else {
        return 0;
    }

}
