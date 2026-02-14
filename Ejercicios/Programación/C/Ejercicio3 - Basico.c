/***********************************************************************************/
/******************************** EJERCICIO C BÁSICO *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crea un programa en C que lea un número entero y calcule su factorial.*/

#include <stdio.h>

int main () {
	long x, i, resultado = 1;
	
	printf ("\n Escribe un numero: ");
	scanf ("%d", &x);
	i = x;
	while (i != 0){
		resultado *= i;
		i--;
	}
	printf ("\n El factorial de %d es: %d",x,resultado);
	return 0;
}

