// registros.c

#include <stdio.h>
#include <string.h>

#define N 3
#define M 20

struct persona
{
	char nombre[M];
	int edad;
};
// *******************************
void lee (struct persona *p)
{
char linea[M];

printf ("Nombre: ");
gets (p->nombre);
printf ("Edad: ");
gets (linea);
sscanf (linea, "%d", &p->edad);
}
// *******************************
void escribe (struct persona agenda[])
{
	int i;
	printf ("Escribe\n");
	printf ("*******\n");
	for (i = 0; i < N; i++) {
		printf ("Num: %d\n", i);
		printf ("Nombre: %s\n", agenda[i].nombre);
		printf ("Edad: %d\n", agenda[i].edad);
		printf ("\n");
	}
}
//*****************
int main (void)
{
struct persona p[N];
int i;

printf ("Lee\n");
printf ("*******\n");
for (i = 0; i < N; i++){
	printf ("Num: %d\n", i);
	lee (&p[i]);
	printf ("\n");
}
escribe (p);

}
