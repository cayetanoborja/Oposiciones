#include <stdio.h>
#include <stdlib.h>

#define filas 3
#define columnas 3

main(){
int **m,*p,i;

m = malloc (filas*sizeof( int *));
m[0] = malloc (filas*columnas*sizeof( int *));
for (i=1;i<filas;i++)
	 m[i]=m[i-1]+columnas;
p=m[0];
free(p);
}
