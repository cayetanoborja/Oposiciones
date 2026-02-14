// arrays2.c

#include <stdio.h>
#define N 3
main ()
{
	int i, v[N];
	for (i = 0; i < N; i++) {
		do {
			printf ("Numero %d: ", i);
			scanf ("%d", &v[i]);
		} while (v[i] < 0);
	}
	for (i = 0; i < N; i++)
		printf ("v[%d]=%d \n", i, v[i]);
}

/* Ejecucion:
Numero 0: 1
Numero 1: -2
Numero 1: 3
Numero 2: -4
Numero 2: 5
v[0]=1
v[1]=3
v[2]=5
*/
