// retorno.c
#include <stdio.h>
#include <stdlib.h>
#define N 10

// **************   
int *primero (void)
{
	int i, v[i];
	for (i = 0; i < 10; i++)
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
