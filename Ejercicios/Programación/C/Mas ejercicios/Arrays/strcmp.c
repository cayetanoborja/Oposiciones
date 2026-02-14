#include <stdio.h>
#include <string.h>
#define N 3
main ()
{
	int i, r;
	char a[N], b[N];

	printf ("Introduce cadena a: ");
	gets (a);
	printf ("Introduce cadena b: ");
	gets (b);
	printf ("strcmp: %d\n", strcmp (a, b));

	i = 0;
	while (a[i] == b[i] && i < N && a[i] != '\0' && b[i] != '\0')
		i++;

	printf ("a[%d]=%d\n", i, a[i]);
	printf ("b[%d]=%d\n", i, b[i]);

	r = a[i] - b[i];

	printf ("Mi strcmp. %d\n", r);

}

/* Ejecucion:
---
Introduce cadena a: a
Introduce cadena b: b
strcmp: -1
a[0]=97
b[0]=98
Mi strcmp. -1
---
Introduce cadena a: a
Introduce cadena b: a
strcmp: 0
a[1]=0
b[1]=0
Mi strcmp. 0
---
Introduce cadena a: ab
Introduce cadena b: a
strcmp: 98
a[1]=98
b[1]=0
Mi strcmp. 98
---
Introduce cadena a: 12
Introduce cadena b: 1
strcmp: 50
a[1]=50
b[1]=0
Mi strcmp. 50
*/
