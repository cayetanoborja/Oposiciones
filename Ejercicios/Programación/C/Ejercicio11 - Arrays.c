/***********************************************************************************/
/******************************** EJERCICIO C ARRAYS *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear un programa que contenga un procedimiento llamado copiarArray que reciba dos 
arrays y el tamaño de los mismos (deben de ser del mismo tamaño) y que consiga copiar 
en el segundo array el contenido del primero.*/

# include <stdio.h>
# define CONST_TAMANO 9

void copiarArray(int array1[], int array2[], int tamano);

int main() {
	int i;
	int tamano = CONST_TAMANO;
	int array1[tamano], array2[tamano];
	
	printf ("\n El primer array contiene los valores: ");
	for (i=0; i<tamano; i++){
		array1[i]=i;
		printf("[%d] ", array1[i]);
	}
	
	copiarArray(array1, array2, tamano);

	printf ("\n\n El segundo array contiene los valores: ");
	for (i=0; i<tamano; i++){
		printf("[%d] ", array2[i]);		
	}
	getchar(); 
	return 0;
}

void copiarArray(int array1[], int array2[], int tamano){
	int i;
	for (i=0; i<tamano; i++){
		array2[i]=array1[i];	
	}
}
