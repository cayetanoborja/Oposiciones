/***********************************************************************************/
/******************************** EJERCICIO C BÁSICO *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crea un programa en C que lea 3 numeros (grados) e indique el tipo de triángulo que 
forman (isósceles, equilátero, escaleno). Comprobar que los números realmente formen 
un triángulo, si no emitir un error. Al terminar tiene que preguntar si se desea 
escribir otro triángulo pudiendo responder S o N.*/

#include <stdio.h>

int main(){
	int x, y, z;
	char opcion = 's';
	
	while (opcion == 's' || opcion == 'S'){
		system ("cls");
		printf("Introduce el primer grado: ");
		scanf("%d", &x);
		printf("\nIntroduce el segundo grado: ");
		scanf("%d", &y);
		printf("\nIntroduce el tercer grado: ");
		scanf("%d", &z);
	
		if (x+y+z != 180)
			printf("\nError, la suma de los grados tiene que ser 180, prueba otra vez.");
		else{
			if (x==60 && y==60 && z==60) //Comprobamos que sea equilátero. Todos sus ángulos son 60.
				printf("\nEl triangulo es equilatero.");
			else if (x==y || x==z || y==z) //Comprobamos que sea isósceles. Tiene 2 ángulos iguales.
				printf("\nEl triangulo es isosceles.");
			else //Si no es ni equilátero ni isósceles, es escaleno.
				printf("\nEl triangulo es escaleno.");
		}
		
		getchar();getchar();
		printf("\nIntentarlo de nuevo? (s/n)");
		scanf("%c", &opcion);
	}
	return 0;
}
