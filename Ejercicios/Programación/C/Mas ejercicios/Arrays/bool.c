#include "stdio.h"
#define t 5
int main (void)
{
	int i;
	for (i = -2; i < 3; i++)
		if (i)
			printf ("%d es V\n", i);
		else
			printf ("%d es F\n", i);
	return 0;
}
