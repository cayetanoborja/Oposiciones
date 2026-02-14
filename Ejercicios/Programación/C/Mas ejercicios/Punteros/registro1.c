#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct
{
	char a[N];
	int b;
} registro;

// **************   
int pedirtalla (int *talla)
{
	char linea[N];
	printf ("Numero de registros: ");
	gets (linea);
	sscanf (linea, "%d", talla);
// NOTA: Si leemos con scanf("%d",talla) nos da problemas con gets
}

// **************
void inicializa (registro * r, int talla)
{
	r = malloc (sizeof (registro) * talla);
	if (r == NULL)
		printf ("Error malloc");
}

// **************
void leer (registro * r, int talla)
{
	int i;
	char linea[N];

	printf ("Leer\n");
	for (i = 0; i < talla; i++) {
		printf ("Cadena %d: ", i);
		gets ((r + i)->a);
		printf ("Numero %d: ", i);
		gets (linea);
		sscanf (linea, "%d", (r + i)->b);
	}
}								// leer

// **************
void escribir (registro * r, int talla)
{
	int i;
	printf ("Escribir\n");
	for (i = 0; i < talla; i++) {
		printf ("cadena %d: %s\n", i, (r + i)->a);
		printf ("Numero %d: %d\n", i, *(r + i)->b);
	}
}

main ()
{
	registro *r;
	int talla;

	pedirtalla (&talla);
	inicializa (r, talla);
	leer (r, talla);
	escribir (r, talla);
}

/* Ejecucion
Numero de registros: 2
Leer
Cadena 0: abc
Numero 0: 1
Cadena 1: hij
Numero 1: 123
Escribir
cadena 0: abc
Numero 0: 1
cadena 1: hij
Numero 1: 123
*/
