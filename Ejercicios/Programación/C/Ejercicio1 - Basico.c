/***********************************************************************************/
/******************************** EJERCICIO C BÁSICO *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crea un programa en C que lea 2 números y que escriba el mayor de los 2.*/

#include <stdio.h>

int main(){
	int num1, num2;
	
	printf("Escribe un numero: ");
	scanf("%d", &num1);
	printf("\nEscribe otro numero: ");
	scanf("%d", &num2);
	
	if (num1>num2)
		printf("\nEl mayor es el primero y su valor es: %d", num1);
	else if (num2>num1)
		printf("\nEl mayor es el segundo y su valor es: %d", num2);
	else
		printf("\nLos numeros son iguales y sus valores son: %d", num1);
	
	return 0;
}
