/* ej220 Pag. 218
*/
#include <stdio.h>
#include <stdlib.h>
#define TALLA 5

float *selecciona (float a[], int talla, int *numpos, int num)
{
		int i, j;
		float *pos;

		*numpos = 0;
		for (i = 0; i < talla; i++)
			if (a[i] > num)
				(*numpos)++;

		pos = malloc (*numpos * sizeof (float));

		j = 0;
		for (i = 0; i < talla; i++)
			if (a[i] > num)
				pos[j++] = a[i];

		return pos;
	}

	
main(){
	int seleccionados, i;
	float *seleccion, num, vector[TALLA];


	printf ("Vector:\n");
	for (i = 0; i < TALLA; i++) {
		printf ("%d: ", i);
		scanf ("%f", &vector[i]);
	}

	printf ("Numero:\n");
	scanf ("%f", &num);

	seleccion = selecciona (vector, TALLA, &seleccionados, num);

	printf ("Vector selecion de mayores que %d:\n", num);
	for (i = 0; i < seleccionados; i++)
		printf ("%f\n", seleccion[i]);

	free (seleccion);
	seleccion = NULL;
}
/*Ejecucion
Vector:
0: 1
1: 5
2: 7
3: 34
4: 3
Numero:
7
Vector selecion de mayores que 0:
34.000000
*/
