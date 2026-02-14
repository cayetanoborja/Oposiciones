/***********************************************************************************/
/******************************** EJERCICIO C BÁSICO *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear un programa que lea un número entero y a partir de él cree un cuadrado de asteriscos
con ese tamaño. Los asteriscos sólo se verán en el borde del cuadrado, no en el interior.*/

#include <stdio.h>

int main () {
	long x, i, j;

	printf ("\n Escribe un numero: ");
	scanf ("%d", &x);
	printf ("\n ");
	
	for (i=0; i<x; i++) {
		printf("\n *");
		if (x == 2)
			printf ("*");
		for (j=1; j<x-1; j++) {
			if ((i==0) || (i ==x-1))
				printf("*");
			else
				printf(" ");    
			if ((j == x-2))
				printf("*");     
		}   
	}
	getchar();getchar();
	return 0;
}

