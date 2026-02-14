/***********************************************************************************/
/************* EJERCICIO FUNCIONES CON Nº VARIABLE DE ARGUMENTOS 1 C ***************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*Escribe una función llamada "Promedio" que devuelva un double y que calcule
el promedio de los parámetros que reciba de tipo "double". El primer parámetro
indica el número de parámetros adicionales que se han pasado a la función.*/

#include <stdio.h>      
#include <stdarg.h>

double Promedio (int Cantidad, ...){
       double suma, promedio;
       int i;
       if (Cantidad <= 0){
             return 0;
       }       
       va_list Parametros; //Declaramos la lista de parámetros opcionales.
       va_start (Parametros, Cantidad); //Inicializamos la lista.
       for (i=0;i<Cantidad;i++){
           suma+= va_arg(Parametros, double);
       }
       va_end (Parametros); //Limpiamos la lista de parámetros opcionales.
       promedio = suma / Cantidad;
       return (promedio);
}

int main (){
    int Cantidad = 4;
    double promedio, a, b, c, d;
    printf ("\n Inserte el valor 1: ");
    scanf ("%lf", &a);
    printf ("\n Inserte el valor 2: ");
    scanf ("%lf", &b);
    printf ("\n Inserte el valor 3: ");
    scanf ("%lf", &c);
    printf ("\n Inserte el valor 4: ");
    scanf ("%lf", &d);
    promedio = Promedio (Cantidad, a, b, c, d);
    printf ("\n El promedio es: %lf", promedio);
    getchar();
    getchar();   
}

