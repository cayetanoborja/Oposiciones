/***********************************************************************************/
/******************************** EJERCICIO C BÁSICO *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/************************************************************************************
Crear un programa en el que se introduce un número entero y se crea un rombo de 
asteriscos. Por ejemplo, si se introduce 4, el resultado sería:
     *
    ***
   *****
  *******
   *****
    ***
     *
     
*/

#include <stdio.h>

int main () {
	long x, i, j;
	
	printf ("\n Escribe un numero: ");
	scanf ("%d", &x);

	//Dibuja un triángulo.
	for (i=1;i<=x;i++) { //Se ejecuta desde la fila 1 hasta la fila x.
			printf("\n ");
		for (j=1;j<=x-i;j++) //Dibuja en esa fila tantos espacios en blanco como "x-i"
			printf(" ");
		for (j=1;j<=(2*i)-1;j++)
			printf("*");
	}

	//Ahora dibuja justo debajo un triángulo invertido.
	x--;
	for (i=1;i<=x;i++) { //Se ejecuta desde la fila 1 hasta la fila x.
		printf("\n ");
		for (j=i-1;j>=0;j--)
		printf(" ");
		for (j=(2*x)-i;j>=i;j--)
		printf("*");
	}       
	getchar(); getchar();
	return 0;
}

