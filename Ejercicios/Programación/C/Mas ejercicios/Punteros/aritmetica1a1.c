/* aritmetica1.c
Crear un vector dinamico de talla 10.
Rellenarlo con los enteros de 0 a 9, dentro del programa.
Imprimir el contenido del vector dinamico por pantalla.
Solo con punteros y aritmetica de punteros.

*/

# include <stdlib.h>
# include <stdio.h>
# define MAX_V 10


main(){   
int *a, *p; // a contendra la matriz y p el puntero que la recorrera
int i;
a = (int*)malloc(MAX_V*sizeof(int));  
for (p=a,i=0;i<MAX_V;i++,p++)
	*p=i;
	 
for (p=a,i=0;i<MAX_V;i++,p++) 
printf("*p=%d \n", *p); 

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
