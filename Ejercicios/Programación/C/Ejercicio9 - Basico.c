/***********************************************************************************/
/******************************** EJERCICIO C BÁSICO *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear un programa en C que muestre un menú con las opciones de 1 - Suma, 2 - Resta y 
3 - Salir. Tras mostrar el menú, se pedirán 2 variables y calculará la suma mediante
una función y la resta mediante un procedimiento.*/

#include <stdio.h>

void resta(int num1, int num2, int *resultado);

int main(){
	int opcion=0, num1, num2, resultado, i;
 	
	while (opcion != 3){
		system ("cls");
		printf ("\n 1 - Suma");
		printf ("\n 2 - Resta");
		printf ("\n 3 - Salir");
		printf ("\n\n Elige una opcion: ");
		scanf ("%d", &opcion);
		
		if (opcion>0 && opcion<3){
			printf("\n Introduce primer numero: ");
			scanf("%d", &num1);
			printf("\n Introduce segundo numero: ");
			scanf("%d", &num2);	
			resultado=0;		
		}
		
		switch (opcion){
			//Caso 1: Suma
			case 1:
 				resultado = suma(num1, num2);
 				printf("\n El resultado de la operacion es: %d", resultado);
			break;
			
			//Caso 2: Resta
 			case 2:
  				resta(num1, num2, &resultado);
  				printf("\n El resultado de la operacion es: %d", resultado);
			break;
			
			//Caso 3: Salir
			case 3:
				printf("\n Adios");
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

int suma(int num1, int num2){
	int valor;
	valor = num1+num2;
	return valor;
}

void resta(int num1, int num2, int *resultado){
	*resultado = num1-num2;
}
