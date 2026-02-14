#include <stdio.h>
#define cuadrado(x)  ((x)*(x))

main ()
{
	int i = 3, z;
	z = cuadrado (i++);
	printf ("i:%d, z:%d\n", i, z);
	i = 3;
	z = cuadrado (++i);
	printf ("i:%d, z:%d\n", i, z);
	return 0;
}

/* Ejecucion:
i:5, z:9
i:5, z:25
*/

/* Nota:
Con z=cuadrado(i++) 
primero calcula 3*3, y despues suma 1 a la i dos veces.

Con z=cuadrado(++i) 
primero suma 1 a la i dos veces y despues calcula 5*5
*/
