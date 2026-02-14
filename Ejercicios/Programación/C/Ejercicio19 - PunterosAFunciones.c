/***********************************************************************************/
/************************ EJERCICIO PUNTEROS A FUNCIONES 1 C ***********************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Implementa un programa que lea 2 números enteros por teclado y realice la suma, resta 
y multiplicación de ambos empleando punteros a funciones que hagan esas operaciones.*/

#include <stdio.h>

int Suma (int a, int b);
int Resta (int a, int b);
int Multiplicacion (int a, int b);

int main ()
{
    int a, b;
    int (*PunteroAFuncion) (int, int);  //Declaramos un puntero a una función.
    
    printf ("\n Inserte el operando 1: ");
    scanf ("%d", &a);
    printf ("\n Inserte el operando 2: ");
    scanf ("%d", &b);
    
    PunteroAFuncion = &Suma; //El puntero apuntará a la dirección de Suma, por lo que PunteroAFuncion es lo mismo que Suma.
    printf ("\n La suma de %d y %d es: %d", a, b, PunteroAFuncion(a,b));

    PunteroAFuncion = &Resta;
    printf ("\n La resta de %d y %d es: %d", a, b, PunteroAFuncion(a,b));
    
    PunteroAFuncion = &Multiplicacion;
    printf ("\n La multiplicacion de %d y %d es: %d", a, b, PunteroAFuncion(a,b));
            
    getchar();
    getchar();
    
}

int Suma (int a, int b){
    return a + b;  
}

int Resta (int a, int b){
    return a - b;  
}

int Multiplicacion (int a, int b){
    return a * b;  
}
