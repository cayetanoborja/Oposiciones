/***********************************************************************************/
/****************************** EJERCICIO EXAMEN 2018 ******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*
Disene un programa en lenguaje C que muestre un menu inicial en el que se indiquen las 
opciones 1-Sumar, 2-Restar, 3-Dividir, 4-Multiplicar y 5-Salir. Tras elegir la opcion 
deseada, se pediran 2 variables y se calculara e indicara el resultado correspondiente. 
En su implementacion no podran utilizarse el operador propio de la multiplicacion (*) ni 
el de la division (/). Asimismo, en el caso de la division, se mostrara solo el cociente, 
comprobando tambien que el denominador introducido no sea igual a 0, en cuyo caso se 
repetira dicha solicitud.*/

#include <stdio.h>
#include <stdlib.h> //Para que funcione system("cls")

int main(){
	int opcion=0, num1, num2, resultado, i;
		
	while (opcion != 5){
		system("cls");
		printf("Ejercicio 2");
		printf("\n1 - Sumar");
		printf("\n2 - Restar");
		printf("\n3 - Multiplicar");
		printf("\n4 - Dividir");
		printf("\n5 - Salir");
		printf("\n\nElige una opcion: ");
		scanf("%d", &opcion);
		
		if (opcion >= 1 && opcion <5){
			printf("\nIntroduce numero 1: ");
			scanf("%d", &num1);
			printf("\nIntroduce numero 2: ");
			scanf("%d", &num2);
		}
		resultado=0;
		
		switch (opcion){
			case 1: //Suma
				resultado=num1+num2;
				printf("\nEl resultado de la operacion es: %d", resultado);
			break;
			case 2: //Resta
				resultado=num1-num2;
				printf("\nEl resultado de la operacion es: %d", resultado);
			break;
			case 3: //Multiplica
				for (i=0;i<num2;i++){
					resultado=resultado+num1;
				}
				printf("\nEl resultado de la operacion es: %d", resultado);
			break;
			case 4: //Divide
				if (num2==0)
					printf("\nNo se puede dividir entre 0, prueba otra vez.");
				else{
					while (num1>=num2){
						num1=num1-num2;
						resultado++;
					}
				printf("\nEl resultado de la operacion es: %d", resultado);
				}
			break;
			case 5: //Sale
				printf("\nHasta luego");
			break;
			default:
				printf("\nOpcion incorrecta, prueba otra vez.");
			break;
		}
		getchar();getchar();
	}
	return 0;
}
