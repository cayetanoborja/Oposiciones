/***********************************************************************************/
/******************************** EJERCICIO C ARRAYS *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear un programa llamado paresImpares que cree un array de 100 números aleatorios del 
1 al 1000. Una vez creado, mostrar el contenido y después organizarlo de forma que 
estén juntos los elementos pares y los impares. Después, volver a mostrar el array*/

# include <stdio.h>

int main() {
	srand (time(NULL)); //Si no hacemos esto, el número aleatorio de rand() será siempre el mismo. Con esto toma como referencia la hora y así cada vez cambia de verdad.
	int i, j=0, k=0, aleatorio;
	int array[100], array2[100], par[100], impar[100];

	//Rellenamos el array de números aleatorios.
	for (i=0;i<100;i++)
		array[i] = rand()%1000;

	//Imprimimos el array1.
	printf ("\n\n El array contiene los siguientes valores: ");
	for (i=0;i<100;i++)
		printf("[%d] ", array[i]);
	
	//Copiamos los pares en par y los impares en impar.
	for (i=0;i<100;i++) {
		if (array[i]%2 == 0) { //Es par.
			par[j] = array[i];
			j++;             
		}
        else { //Es impar.
  			impar[k] = array[i];
			k++;
		}         
	}
	
	//Copiamos los impares a la izquierda del array2.
	for (i=0;i<k;i++)
		array2[i] = impar[i];

	//Copiamos los impares a la izquierda del array2.
	for (i=0;i<j;i++) {
 		array2[k] = par[i];
		k++;
	}
        
	//Imprimimos el array2.
	printf ("\n\n El array 2 contiene los siguientes valores: ");
	for (i=0;i<100;i++)
		printf("[%d] ", array2[i]);
	getchar(); 
}


