/* aritmetica1.c
Crear un vector dinamico de talla 10.
Rellenarlo con los enteros de 0 a 9, dentro del programa.
Imprimir el contenido del vector dinamico por pantalla.
*/
# include <stdlib.h>
# include <stdio.h>
# define MAX_V 10


main(){   
int *a, *p; 
int i;
a = (int*)malloc(MAX_V*sizeof(int));  
for (p=a;p-a<MAX_V;p++)
	*p=p-a; 

	 
for (p=a;p-a<MAX_V;p++) 
printf("*p=%d p:%u a:%u p-a:%u\n", *p, p, a, p-a); 

free(a); 
a=NULL;  
}
/* Ejecucion
*p=0 p:134520840 a:134520840 p-a:0
*p=1 p:134520844 a:134520840 p-a:1
*p=2 p:134520848 a:134520840 p-a:2
*p=3 p:134520852 a:134520840 p-a:3
*p=4 p:134520856 a:134520840 p-a:4
*p=5 p:134520860 a:134520840 p-a:5
*p=6 p:134520864 a:134520840 p-a:6
*p=7 p:134520868 a:134520840 p-a:7
*p=8 p:134520872 a:134520840 p-a:8
*p=9 p:134520876 a:134520840 p-a:9
*/
