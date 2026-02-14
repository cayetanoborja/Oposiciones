// listasimplemain.c
#include <stdio.h>
#include <stdlib.h>
#include "listasimple.h"

int main (void)
{

	int opcion, valor;
	TipoLista lista;
	char linea[80];

	lista = lista_vacia ();

	do {
		printf ("Menu Listas Simples\n");
		printf ("0) Salir\n");
		printf ("1) Vaciar lista\n");
		printf ("2) Insertar por cabeza\n");
		printf ("3) Ver lista\n");
		printf ("4) Longuitud lista\n");
		printf ("5) Inserta por la cola\n");
		printf ("6) Borra por la cabeza\n");
		printf ("7) Borra por la cola\n");
		printf ("8) Pertenece\n");

		printf ("Opcion: ");
		gets (linea);
		sscanf (linea, "%d", &opcion);

		switch (opcion) {

		case 1:
			lista = lista_vacia ();
			break;

		case 2:
			printf ("Valor: ");
			gets (linea);
			sscanf (linea, "%d", &valor);
			lista = inserta_por_cabeza (lista, valor);
			muestra_lista (lista);
			break;

		case 3:
			muestra_lista (lista);
			break;

		case 4:
			printf ("La longuitud de la lista es: %d\n",
					longitud_lista (lista));
			break;


		case 5:
			printf ("Valor: ");
			gets (linea);
			sscanf (linea, "%d", &valor);
			lista = inserta_por_cola (lista, valor);
			muestra_lista (lista);
			break;

		case 6:
			lista = borra_cabeza (lista);
			muestra_lista (lista);
			break;

		case 7:
			lista = borra_cola (lista);
			muestra_lista (lista);
			break;

		case 8:
			printf ("Valor: ");
			gets (linea);
			sscanf (linea, "%d", &valor);
			if (pertenece (lista, valor))
				printf ("Pertenece\n", valor);
			else
				printf ("%d no pertenece\n", valor);
			muestra_lista (lista);
			break;

		}
	} while (opcion != 0);

	return 0;
}
