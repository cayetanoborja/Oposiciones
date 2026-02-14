/* leerlinea.c
Hacer un programa que llame a una funcion,
que devuelve la linea leida por teclado
que se pasa como parametro,
la cual debera usar fgetc, para leer
la linea caracter a caracter.

int leerlinea(char linea[], int max)
Lee caracter a caracter con fgetc y los mete en la
cadena linea, devuelve la longuitud. La longuitud
de linea es como maximo max.

Despues imprima el contenido de la cadena por pantalla.
*/

#include <stdio.h>
#include <string.h>
#define N 100
// ************
int leerlinea(char linea[], int max)
{
int i=0,seguir=1;
char c;
	while (i < max-1 && seguir ){
	c=fgetc(stdin);
	seguir=(c!='\n');
	// En lugar de \n se puede usar EOF
	if (seguir) linea[i]=c;
		i++;
	}
linea[i]='\0';
return i-1;
}

// ********************
main(){
char linea[N];
int l=0;

printf("Introduce la linea: ");
l=leerlinea(linea,N);
printf("Longuigud: %d\nLinea: %s\n",l,linea);

}

/* Ejecucion
Introduce la linea: 1 2 345
Longuigud: 7
Linea: 1 2 345
*/
