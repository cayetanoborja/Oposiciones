#include <stdio.h>
#include <stdlib.h>
#define N 3

// **************   
int *primero (void)
{
	int *v;
	int i;

	v = malloc (N * sizeof (int));

	for (i = 0; i < N; i++)
		v[i] = i + 1;

	return v;
}

// *********** MAIN
main ()
{
	int *a;
	a = primero ();
	printf ("%d ", a[0]);
}
