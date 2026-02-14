/* Fichero agenda1.c
Contiene simplemente la funcion main
*/

#include "agenda1.h"

// *************************
main ()
{
agenda a;
int opcion;

a.cantidad = 0;
do {
	opcion = menu ();
	switch (opcion) {
	case 1:
		listar (a);
		break;
	case 2:
		anadir (&a);
		break;
	}
} while (opcion != 0);
}
