#include <stdio.h>
#define N 3
main ()
{
	int i, v[N];
	for (i = 0; i < N; i++) {
		printf ("Numero %d: ", i);
		scanf ("%d", &v[i]);
	}
	for (i = 0; i < N; i++)
		printf ("v[%d]=%d \n", i, v[i]);
}

/* Ejecución:
Numero 0: 1
Numero 1: 2
Numero 2: 3
v[0]=1
v[1]=2
v[2]=3
*/
