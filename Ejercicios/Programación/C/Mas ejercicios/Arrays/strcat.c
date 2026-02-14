//strcat.c
#include <stdio.h>
#include <string.h>
#define N 5
main ()
{
	int i, j;
	char a1[N], a[N], b[N];

	printf ("Introduce cadena a: ");
	gets (a);
	printf ("Introduce cadena b: ");
	gets (b);

	strcpy (a1, a);
	strcat (a1, b);
	printf ("strcat: %s\n", a1);

	i = 0;
	while (a[i])
		i++;

	j = 0;
	while (b[j] && i < N) {
		a[i] = b[j];
		i++;
		j++;
	}
	a[i] = '\0';
	printf ("Mi strcat. %s \n", a);

}

/* Ejecucion:
Introduce cadena a: ab
Introduce cadena b: c
strcat: abc
Mi strcat. abc
---
NOTA: 
Si no ponemos i<N 
nos pasamos del tamanyo y
sale error de ejecucion.
es decir:
Introduce cadena a: abc
Introduce cadena b: def
strcat: abcdef
Violacion de segmento
*/

/* Nota:
strcat (a,b) devuelve la cadena a concatenada
es decir, printf("%s %s", strcat(a,b),a); imprimiria
dos veces la cadena a.
*/
