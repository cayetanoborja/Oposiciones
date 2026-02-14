/* estructura.c
Hacer un programa en C, con un menu, que permita
anyadir registros por teclado y listar los registros contenidos en el
fichero.
No se deberan perder los registros introducidos en
ejecuciones anteriores.
*/

#include <stdio.h>

typedef struct
{
	char nombre[20];
	char telefono[15];
	char email[20];
} registro;

#define NOMBRE "fichero.dat"
#define T sizeof(registro)
#define MAXLINEA 80

// *******************
int menu (void)
{
	char linea[MAXLINEA];
	int op;
	do {
		printf ("**************\n");
		printf ("Menu agenda con ficheros\n");
		printf ("0. Salir\n");
		printf ("1. Leer Registros\n");
		printf ("2. Imprimir Resgristros\n");
		printf ("Opcion?: ");
		gets (linea);
		sscanf (linea, "%d", &op);
	} while (op < 0 || op > 2);
	return op;
}
// *************************
void leerregistro (registro *r){
	printf ("Nombre: ");
	gets (r->nombre);
	printf ("Telefono: ");
	gets (r->telefono);
	printf ("Email: ");
	gets (r->email);
}
	
// *************************
void leer (){
FILE *f;
registro r;
int seguir=1,res='s';
char linea[MAXLINEA];
	
f=fopen(NOMBRE,"rb+");
if (f==NULL)
printf("Error: No se pudo abrir para escritura %s\n",NOMBRE);

printf ("**************\n");
printf ("Lectura de registros de la agenda\n");

 while (seguir) {
 leerregistro(&r);
 fwrite(&r,T,1,f);
 printf("Seguir? (s/n): ");
 gets(linea);
 sscanf(linea,"%c",&res);
 seguir = (res!='n');
 }
fclose(f);
}
// *************************
void escriberegistro(registro r)
{
printf ("Nombre   : %s\n", r.nombre);
printf ("Telefono : %s\n", r.telefono);
printf ("Email    : %s\n", r.email);
}

// *************************
void escribir (){
FILE *f;
registro r;
int i=1;
	
f = fopen(NOMBRE,"rb");
if (f==NULL)
  printf("Error: No se pudo abrir para lectura %s\n",NOMBRE);

printf ("**************\n");
printf ("Listado de la agenda\n");

fread(&r,T,1,f);
while (!feof(f)) {
  printf ("Numero   : %d\n", i++);
  escriberegistro(r);
  fread(&r,T,1,f);
}
fclose(f);
}

// *************************
main ()
{
int opcion;
do {
	opcion = menu ();
	switch (opcion) {
	case 1:
		leer();
		break;
	case 2:
		escribir();
		break;
	}
} while (opcion != 0);
}
