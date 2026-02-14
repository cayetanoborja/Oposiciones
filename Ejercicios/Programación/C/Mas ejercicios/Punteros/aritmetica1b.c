/* aritmetica1.c
Crear un vector dinamico de talla 10.
Rellenarlo con los enteros de 0 a 9, dentro del programa.
Imprimir el contenido del vector dinamico por pantalla.
*/

# include <stdlib.h>
# include <stdio.h>
# define MAX_V 10


main(){   
int *a; 
int i;
	
a = (int*)malloc(MAX_V*sizeof(int));  
for (i=0;i<MAX_V;i++)
	a[i]=i;
	 
for (i=0;i<MAX_V;i++) 
printf("*p=%d \n", a[i]); 

free(a); 
a=NULL;  
}
/* Ejecucion
*p=0
*p=1
*p=2
*p=3
*p=4
*p=5
*p=6
*p=7
*p=8
*p=9
*/
