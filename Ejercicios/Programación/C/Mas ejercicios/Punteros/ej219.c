#define <stdio.h>
#define <stdlib.h>
#declare N 10
#declare MAXREG 10

typedef struc
{
	char a[N];
	int b;
} registro;

// **************   
int pedirtalla ()
{
	int talla;
	printf ("Numero de registros");
	gets (linea);
	sscanf (linea, "%d", &talla);
	return talla;
}

// **************
void inicializa (registro * r, int talla)
{
	r = malloc (sizeof (registro) * talla if (r == NULL)
				printf ("Error malloc");}

// **************
				void leer (registro * r, int talla)
				{
				int i; for (i = 0; i < talla; i++) {
				printf ("num: %d\n", i);
				printf ("a: "); gets (r[i]->a);
				printf ("b: "); gets (linea); sscanf (linea, "%d", r[i]->b);}
				}				// leer

// **************
				void escribir (registro * r, int talla)
				{
				int i; for (i = 0; i < talla; i++) {
				printf ("num: %d\n", i);
				printf ("a: ", r[i]->a); printf ("b: " r[i]->b);}
				}

// *********** MAIN
				main {
				}

				{
				registro * r;
				int talla;
				pedirtalla (&talla); inicializa (r, talla); leer (r, talla)
				escribir (r, talla);}
				}

// **************   
				int pedirtalla ()
				{
				int talla;
				printf ("Numero de registros"); gets (linea);
				sscanf (linea, "%d", &talla); return talla;}
// **************
				void inicializa (registro * r, int talla)
				{
				r = malloc (sizeof (registro) * talla if (r == NULL)
							printf ("Error malloc");}

// **************
							void leer (registro * r, int talla)
							{
							int i; for (i = 0; i < talla; i++) {
							printf ("num: %d\n", i);
							printf ("a: "); gets (r[i]->a);
							printf ("b: "); gets (linea);
							sscanf (linea, "%d", r[i]->b);}
							}	// leer

// **************
							void escribir (registro * r, int talla)
							{
							int i; for (i = 0; i < talla; i++) {
							printf ("num: %d\n", i);
							printf ("a: ", r[i]->a); printf ("b: " r[i]->b);}
							}
