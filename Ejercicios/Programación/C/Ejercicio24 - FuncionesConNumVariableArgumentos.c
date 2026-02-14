/***********************************************************************************/
/************* EJERCICIO FUNCIONES CON Nº VARIABLE DE ARGUMENTOS 2 C ***************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*Escribe una función llamada "listar" que imprima por pantalla los parámetros
que se le pasen de tipo entero. El último parámetro debe valer -1 para indicar
el final de la lista de parámetros. Como mínimo se recibirá un parámetro que
también puede valer -1, indicando así que no se quiere mostrar nada por pantalla.*/

#include <stdio.h>      
#include <stdarg.h>

double Listar (int primero, ...){
       
       va_list parametros;
       int k;
       
       va_start (parametros, primero);
       
       k = primero;
       while (k != -1){
             printf ("%d ", k);
             k = va_arg (parametros, int);
       }
       
       va_end (parametros);
}

int main (){
}

