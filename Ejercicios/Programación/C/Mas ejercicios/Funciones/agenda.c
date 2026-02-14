// agenda.c

#include <stdio.h>

#define PERSONAS 5
#define CADENA 20
#define MAXLINEA 20

typedef struct
{
	char clave[20];
	char nombre[20];
	char telefono[15];
	char email[20];
} registro;

typedef struct
{
	registro persona[PERSONAS];	// vector de registros
	int cantidad;				// elementos de persona rellenos
} agenda;

//*********************
int menu (void);
void listar (agenda a);
void anadir (agenda * a);
int compara (char cadena1[], char cadena2[]);
//*********************
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
//*********************
int menu (void)
{
	char linea[MAXLINEA];
	int op;

	do {
		printf ("==========\n");
		printf ("Menu\n");
		printf ("0. Salir\n");
		printf ("1. Listar\n");
		printf ("2. Nuevo\n");
		printf ("Opcion?: ");
		gets (linea);
		sscanf (linea,"%d", &op);
	} while (op < 0 || op > 2);
	return op;
}
//*********************
void listar (agenda a)
{
	int i;
    printf ("====================\n");
	printf ("Listado de la agenda\n");
	for (i = 0; i < a.cantidad; i++) {
		printf ("Numero   : %d\n", i);
		printf ("Codigo   : %s\n", a.persona[i].clave);
		printf ("Nombre   : %s\n", a.persona[i].nombre);
		printf ("Telefono : %s\n", a.persona[i].telefono);
		printf ("Email    : %s\n", a.persona[i].email);
		printf ("\n");
	}

}
//*********************
void obtenerclave (char nombre[], char telefono[], char clave[])
{
	int i = 1, j = 0;

	clave[0] = nombre[0];
	while (telefono[j] != '\0') {
		clave[i] = telefono[j];
		i++;
		j++;
	}
	clave[i] = '\0';
}
//*********************
void pedirregistro (registro * r)
{
	printf ("Nombre : ");
	gets (r->nombre);
	printf ("Telefono : ");
	gets (r->telefono);
	printf ("Email : ");
	gets (r->email);
	obtenerclave (r->nombre, r->telefono, r->clave);
}
//*********************
int compara (char a[], char b[])
{
	int i = 0;

	while (a[i] == b[i] && i < CADENA && a[i] != '\0')
		i++;
	return a[i] - b[i];
}
//*********************
void personanueva (agenda * a, registro r)
{
int i = 0, j;
while (i < a->cantidad && compara (a->persona[i].nombre, r.nombre) < 0)
		i++;
// desplazamos una posicion a la derecha
j = i;
while (j < a->cantidad) {
	a->persona[j + 1] = a->persona[j];
	j++;
}
a->persona[i] = r;
a->cantidad++;
}
//*********************
void anadir (agenda * a)
{
registro r;
if (a->cantidad == PERSONAS)
	printf ("Lleno");
else {
	pedirregistro (&r);
	personanueva (a, r);
}
}
