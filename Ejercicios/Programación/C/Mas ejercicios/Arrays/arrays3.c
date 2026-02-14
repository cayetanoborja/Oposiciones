// arrays3.c

#include <stdio.h>
#define N 3
main ()
{
	int i, v[N], n, encontrado;
// Leemos los numeros
	for (i = 0; i < N; i++) {
		printf ("Numero %d: ", i);
		scanf ("%d", &v[i]);
	}
// Buscamos numeros
	do {
		printf ("Numero a buscar: (fin <0): ");
		scanf ("%d", &n);

		encontrado = (v[0] == n);
		i = 1;
		while (!encontrado && i < N) {
			encontrado = (v[i] == n);
			i++;
		}
		if (encontrado)
			printf ("Encontrado numero %d en la posicion %d\n", n, i - 1);
		else
			printf ("No encontrado numero %d\n", n, i - 1);
	} while (n > 0);
}

/* Ejecucion:
Numero 0: 1
Numero 1: 2
Numero 2: 3
Numero a buscar: (fin <0): 5
No encontrado numero 5
Numero a buscar: (fin <0): 2
Encontrado numero 2 en la posicion 1
Numero a buscar: (fin <0): -1
No encontrado numero -1
*/
