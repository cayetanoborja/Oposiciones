/***********************************************************************************/
/******************************** EJERCICIO C BÁSICO *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear un programa en C que muestre un menú como el siguiente:
      1) Salir.
      2) Sumatorio.
      3) Factorial.
Tras mostrar el menú, el programa debe leer un número del 1 al 3. Si se elige 1, el
programa acaba. Si se elige 2 se calcula el sumatorio del número, si se elige 3 se
calcula el factorial (en ambos casos el programa pedirá escribir el número). Tras
calcular el sumatorio o el factorial e indicar el resultado, el programa volverá a
mostrar el menú y así sucesivamente.*/

#include <stdio.h>

int main(){
 	int opcion=0, numero, resultado, i;
 	
	while (opcion != 1){
		system ("cls");
		printf ("\n 1) Salir");
		printf ("\n 2) Sumatorio");
		printf ("\n 3) Factorial");
		printf ("\n\n Elige una opcion: ");
		scanf ("%d", &opcion);
		
		switch (opcion){
			//Caso 1: Salir
			case 1:
 				printf("\n Adios\n");
			break;
			
			//Caso 2: Sumatorio
 			case 2:
  				printf ("\n Introduce un numero: ");
				scanf ("%d", &numero);
				printf ("\n La sumatoria de %d", numero);
				resultado = 0;
				while (numero != 0){
					resultado = resultado + numero;
   					numero--;
				}
				printf (" es %d", resultado);
			break;
			
			//Caso 3: Factorial
			case 3:
				printf ("\n Introduce un numero: ");
				scanf ("%d", &numero);
				printf ("\n El factorial de %d", numero);
				if (numero != 0) {
   					resultado = 1;
   					while (numero != 1) {
						resultado = resultado * numero;
						numero--;
  					}
				}
				else
					resultado = 0;
 					printf (" es %d", resultado);
				break;
				
			//Caso otro: Opción incorrecta
			default:
				printf ("\n Opcion incorrecta, vuelve a intentarlo\n");
			break;
		}   
		getchar(); getchar();
	}
	return 0;
}
